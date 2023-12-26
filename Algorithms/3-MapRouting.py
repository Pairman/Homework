from math import sqrt
from timeit import default_timer as time
from io import StringIO, TextIOWrapper

EPSILON, INFINITY = 0.000001, float("inf")

class IndexMinPQ:
	def __init__(self, max_size):
		self.max_size, self.size = max_size, 0
		self.keys = {i: None for i in range(self.max_size + 1)}
		self.arr = [0 for i in range(self.max_size + 1)]
		self.onq = [-1 for i in range(self.max_size + 1)]

	def __bool__(self):
		return not not self.size

	def __gt(self, i, j):
		return self.keys[self.arr[i]] > self.keys[self.arr[j]]

	def __exch(self, i, j):
		self.arr[i], self.arr[j] = self.arr[j], self.arr[i]
		self.onq[self.arr[i]], self.onq[self.arr[j]] = i, j

	def __swim(self, k):
		while k > 1 and self.__gt(k // 2, k):
			self.__exch(k // 2, k)
			k //= 2

	def __sink(self, k):
		while (j := k * 2) <= self.size:
			if j < self.size and self.__gt(j, j + 1):
				j += 1
			if not self.__gt(k, j):
				break
			self.__exch(k, j)
			k = j

	def has(self, i):
		return self.onq[i] != -1

	def push(self, i, key):
		if self.size >= self.max_size:
			return
		self.onq[i] = self.size = self.size + 1
		self.arr[self.size] = i
		self.keys[i] = key
		self.__swim(self.size)

	def pop(self):
		if self.size <= 0:
			return
		min = self.arr[1]
		self.__exch(1, self.size)
		self.size -= 1
		self.__sink(1)
		self.arr[self.size + 1], self.onq[min], self.keys[min] = -1, -1, None
		return min

	def lower(self, i, key):
		self.keys[i] = key
		self.__swim(self.onq[i])

class Edge:
	def __init__(self, v, w, weight):
		self.v, self.w, self.weight = v, w, weight

	def __repr__(self):
		return "<%d-%d|%.2f>" % (self.v, self.w, self.weight)

	def other(self, v):
		return self.w if v == self.v else self.v if v == self.w else None

class Map:
	def __init__(self, file: TextIOWrapper | StringIO):
		self.V, E = map(int, file.readline().split())
		_, self.X, self.Y = zip(*(map(int, file.readline().split()) for i in range(self.V)))
		self.E, self.adj = 0, [[] for v in range(self.V)]
		file.readline()
		for i in range(E):
			line = file.readline().split()
			self.addedge(*map(int, line))

	def __repr__(self):
		return "%d %d\n" % (self.V, self.E) + "\n".join("%d: " % v + " ".join(map(str, self.adj[v])) for v in range(self.V))

	def geodist(self, v, w):
		return sqrt((self.X[v] - self.X[w]) ** 2 + (self.Y[v] - self.Y[w]) ** 2)

	def addedge(self, v, w):
		self.adj[v].append(e := Edge(v, w, self.geodist(v, w)))
		self.adj[w].append(e)
		self.E += 1

	def edges(self):
		return [e for v in range(self.V) for e in self.adj[v] if e.other(v) > v]

class DijkstraSP:
	def __init__(self, G: Map, s, d = None):
		self.s, self.d = s, d
		self.edgeto = [None for i in range(G.V)]
		self.distto = [INFINITY for i in range(G.V)]
		self.distto[s] = 0.0
		self.pq = IndexMinPQ(G.V)
		self.pq.push(s, self.distto[s])
		while self.pq:
			if self.distto[d] < INFINITY:
				break
			v = self.pq.pop()
			self.relax(G, v)

	def __repr__(self):
		return " ".join("<%d-%d|%.2f>" % (self.s, v, self.pathto(v)[0]) for v in range(len(self.distto)))

	def relax(self, G: Map, v):
		for e in G.adj[v]:
			w = e.other(v)
			# if self.distto[w] > (dist := self.distto[v] + e.weight):
			if self.distto[w] - EPSILON > (dist := self.distto[v] + e.weight + G.geodist(w, self.d) - G.geodist(v, self.d)):
				self.distto[w] = dist
				self.edgeto[w] = e
				if self.pq.has(w):
					self.pq.lower(w, dist)
				else:
					self.pq.push(w, dist)

	def haspathto(self, v):
		return self.distto[v] < INFINITY

	def pathto(self, w):
		if not self.haspathto(w):
			return INFINITY, []
		dist, path = 0.0, []
		v, e = w, self.edgeto[w]
		while e:
			w = v
			dist += e.weight
			path.append(e)
			e = self.edgeto[v := e.other(w)]
		return dist, list(reversed(path))

def test(file_map: TextIOWrapper | StringIO, file_query: TextIOWrapper | StringIO = None, verbose = 0):
	print("Constructing map.")
	g = Map(file = file_map)
	print("Query started.")
	while (line := file_query.readline()):
		s, d = map(int, line.split())
		print(end = "<%d-%d|" % (s, d), flush = True)
		start = time()
		SP = DijkstraSP(g, s, d)
		end = time()
		dist, path = SP.pathto(d)
		print("%.2f> %.2fs" % (dist, end - start))
		if verbose:
			print(" -> ".join(map(str, path)))
			if verbose == 2:
				print(SP)

# tiny.txt
# test(open("3/tiny.txt", "r"), StringIO("0 1\n0 2\n0 3\n0 4\n0 5\n3 5\n3 1\n3 4"), verbose = 2)

# usa.txt
test(open("3/usa.txt", "r"), open("3/usa-100long.txt", "r"), verbose = 0)
