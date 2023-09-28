from math import sqrt
from random import SystemRandom
from timeit import default_timer as time

ij2pos = lambda N, i, j: i * N + j
mean = lambda X: sum(X) / len(X)
stddev = lambda X: sum(((x - mean(X)) * (x - mean(X)) for x in X)) / (len(X) - 1)
confidence = lambda X: (mean(X) - 1.96 * sqrt(stddev(X)) / sqrt(len(X)), mean(X) + 1.96 * sqrt(stddev(X)) / sqrt(len(X)))

class UnionFind:
	size, id = None, None

	def __init__(self, N):
		self.size = N
		self.id = [pos for pos in range(N)]

	def find(self, p):
		return self.id[p]

	def connected(self, p, q):
		return self.find(p) == self.find(q)

	def union(self, p, q):
		pID, qID = self.find(p), self.find(q)
		if pID == qID:
			return
		for pos in range(self.size):
			if self.id[pos] == pID:
				self.id[pos] = qID

class QuickUnion(UnionFind):
	def __init__(self, N):
		super().__init__(N)

	def find(self, p):
		while p != self.id[p]:
			p = self.id[p]
		return p

	def union(self, p, q):
		pRoot, qRoot = self.find(p), self.find(q)
		if pRoot == qRoot:
			return
		self.id[pRoot] = qRoot

class WeightedQuickUnion(QuickUnion):
	sz = None

	def __init__(self, N):
		super().__init__(N)
		self.sz = [1 for pos in range(N)]

	def union(self, p, q):
		pRoot, qRoot = self.find(p), self.find(q)
		if pRoot == qRoot:
			return
		if self.sz[pRoot] < self.sz[qRoot]:
			self.id[pRoot] = qRoot
			self.sz[qRoot] += self.sz[pRoot]
		else:
			self.id[qRoot] = pRoot
			self.sz[pRoot] += self.sz[qRoot]

class Percolation:
	size, opened, state, uf = None, None, None, None

	def __init__(self, N = 20, typename = WeightedQuickUnion):
		self.size, self.opened = N, 0
		self.state = [0 for pos in range(N * N + 2)]
		self.uf = typename(N * N + 2)

	def isOpen(self, i, j):
		return self.state[ij2pos(self.size, i, j) + 1]

	def isFull(self, i, j):
		return 0 if not self.isOpen(i, j) else 1 if self.uf.connected(ij2pos(self.size, i, j) + 1, 0) else 0

	def isPercolative(self):
		return self.uf.connected(self.size * self.size, 0)

	def open(self, i, j):
		if self.isOpen(i, j):
			return
		self.opened += 1
		self.state[ij2pos(self.size, i, j) + 1] = 1
		if i == 0:
			self.uf.union(ij2pos(self.size, i, j) + 1, 0)
		elif i == self.size - 1:
			self.uf.union(ij2pos(self.size, i, j) + 1, self.size * self.size)
		if i - 1 >= 0 and self.isOpen(i - 1, j):
			if i - 1 == 0:
				self.uf.union(ij2pos(self.size, i - 1, j) + 1, 0)
			self.uf.union(ij2pos(self.size, i, j) + 1, ij2pos(self.size, i - 1, j) + 1)
		if i + 1 < self.size and self.isOpen(i + 1, j):
			if i + 1 == self.size - 1:
				self.uf.union(ij2pos(self.size, i + 1, j) + 1, self.size * self.size)
			self.uf.union(ij2pos(self.size, i, j) + 1, ij2pos(self.size, i + 1, j) + 1)
		if j - 1 >= 0 and self.isOpen(i, j - 1):
			self.uf.union(ij2pos(self.size, i, j) + 1, ij2pos(self.size, i, j - 1) + 1)
		if j + 1 < self.size and self.isOpen(i, j + 1):
			self.uf.union(ij2pos(self.size, i, j) + 1, ij2pos(self.size, i, j + 1) + 1)

def singleSimulation(N = 20, typename = WeightedQuickUnion, verbose = 1):
	pc = Percolation(N, typename)
	rng = SystemRandom()
	timeElapsed = time()
	while 1:
		pc.open(rng.randint(0, N - 1), rng.randint(0, N - 1))
		if pc.isPercolative():
			timeElapsed = time() - timeElapsed
			if verbose == 1:
				print("\033[32m%dx%d\033[0m Simulation: Percolates opening \033[32m%d/%d\033[0m(\033[32m%.13lf\033[0m) sites, time elapsed \033[32m%.13lfs\033[0m with \033[32m%s\033[0m." % (N, N, pc.opened, N * N, pc.opened / (N * N), timeElapsed, typename.__name__))
			return pc.opened, timeElapsed

def multipleSimulation(N = 20, T = 30, typename = WeightedQuickUnion, verbose = 1):
	sitesOpenedPerrun, siteOpenedOverall, timeElapsedOverall = [None for t in range(T)], 0, 0
	for t in range(T):
		if verbose == 1:
			print(("\033[32m%" + str(len(str(T))) + "d.\033[0m ") % (t + 1), end = "")
		sitesOpenedPerrun[t], timeElapsed = singleSimulation(N, typename, verbose)
		siteOpenedOverall += sitesOpenedPerrun[t]
		timeElapsedOverall += timeElapsed
	if verbose:
		print("\033[33m%d %dx%d\033[0m Simulations: Percolates opening \033[33m%d/%d\033[0m(\033[33m%.13lf\033[0m) sites, time elapsed \033[33m%.13lfs\033[0m with \033[33m%s\033[0m." % (T, N, N, siteOpenedOverall, N * N * T, siteOpenedOverall / (N * N * T), timeElapsedOverall, typename.__name__))
	return sitesOpenedPerrun, siteOpenedOverall, timeElapsedOverall

# Statistical measurements
N, T = 20, 30
X = [x / (N * N) for x in multipleSimulation(N, T, UnionFind, 1)[0]]
print("mean: %.13lf, stddev: %.13lf, confidence: [%.13lf, %.13lf]" % (mean(X), stddev(X), confidence(X)[0], confidence(X)[1]))

# Complexity measurements
for N in (20, 40, 80, 160, 320):
	singleSimulation(N, UnionFind)
	singleSimulation(N, WeightedQuickUnion)
