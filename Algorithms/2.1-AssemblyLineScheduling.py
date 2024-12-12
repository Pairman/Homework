from random import randint
from timeit import default_timer as time
import tracemalloc
from copy import deepcopy

def BinAssemblyLineSchedulingPath(
	a: list[list[float]], t: list[list[float]], e: list[int], x: list[int]
) -> tuple[float, list[int]]:
	def merge(left, right):
		(lcost, lpath), (rcost, rpath) = left, right
		return lcost + rcost, lpath + rpath[1: ]
	def solve(start, end):
		if start == end:
			# contains:
			# assembly time in [start, end)
			# transfer time to the end
			return (
				(a[0][start], [0, 0]),
				(a[0][start] + t[0][start], [0, 1]),
				(a[1][start] + t[1][start], [1, 0]),
				(a[1][start], [1, 1])
			)
		mid = (start + end) // 2
		left00, left01, left10, left11 = solve(start, mid)
		right00, right01, right10, right11 = solve(mid + 1, end)
		return (
			# 00: 00->00, 01->10
			min(merge(left00, right00), merge(left01, right10)),
			# 01: 00->01, 01->11
			min(merge(left00, right01), merge(left01, right11)),
			# 10: 10->00, 11->10
			min(merge(left10, right00), merge(left11, right10)),
			# 11: 10->01, 11->11
			min(merge(left10, right01), merge(left11, right11))
		)
	# calculate entry and exit time along with a[i][0], a[i][n - 1]
	a[0][0] += e[0]
	a[1][0] += e[1]
	a[0][-1] += x[0]
	a[1][-1] += x[1]
	cost, path = min(solve(0, len(a[0]) - 1))
	return cost, path[: -1]

def DPAssemblyLineSchedulingPath(
	a: list[list[float]], t: list[list[float]], e: list[int], x: list[int]
) -> tuple[float, list[int]]:
	f = [[0] * len(a[0]) for _ in range(2)]
	l = [[0] * len(a[0]) for _ in range(2)]
	f[0][0] = e[0] + a[0][0]
	f[1][0] = e[1] + a[1][0]
	for j in range(1, len(a[0])):
		f[0][j], l[0][j] = min(
			(f[0][j - 1] + a[0][j], 0),
			(f[1][j - 1] + t[1][j - 1] + a[0][j], 1),
		)
		f[1][j], l[1][j] = min(
			(f[0][j - 1] + t[0][j - 1] + a[1][j], 0),
			(f[1][j - 1] + a[1][j], 1)
		)
	cost, last = min(
		(f[0][len(a[0]) - 1] + x[0], 0),
		(f[1][len(a[0]) - 1] + x[1], 1)
	)
	def genpath(l, i, j, path = []):
		top = not path
		if j:
			genpath(l, l[i][j - 1], j - 1)
			path.append(i)
		if top:
			return path
	return cost, genpath(l, last, len(a[0]))

# a = [[7, 9, 3, 4, 8, 4], [8, 5, 6, 4, 5, 7]]
# t = [[2, 3, 1, 3, 4, 3], [2, 1, 2, 2, 1, 2]]
# e = [2, 4]
# x = [3, 2]

# # O(nlogn)
# print(BinAssemblyLineSchedulingPath(deepcopy(a), deepcopy(t), e, x))
# print(DPAssemblyLineSchedulingPath(a, t, e, x))

def BinAssemblyLineScheduling(
	a: list[list[float]], t: list[list[float]], e: list[int], x: list[int]
) -> tuple[float, list[int]]:
	def merge(left, right):
		return left + right
	def solve(start, end):
		if start == end:
			# contains:
			# assembly time in [start, end)
			# transfer time to the end
			return (
				(a[0][start]),
				(a[0][start] + t[0][start]),
				(a[1][start] + t[1][start]),
				(a[1][start])
			)
		mid = (start + end) // 2
		left00, left01, left10, left11 = solve(start, mid)
		right00, right01, right10, right11 = solve(mid + 1, end)
		return (
			# 00: 00->00, 01->10
			min(merge(left00, right00), merge(left01, right10)),
			# 01: 00->01, 01->11
			min(merge(left00, right01), merge(left01, right11)),
			# 10: 10->00, 11->10
			min(merge(left10, right00), merge(left11, right10)),
			# 11: 10->01, 11->11
			min(merge(left10, right01), merge(left11, right11))
		)
	# calculate entry and exit time along with a[i][0], a[i][n - 1]
	a[0][0] += e[0]
	a[1][0] += e[1]
	a[0][-1] += x[0]
	a[1][-1] += x[1]
	return min(solve(0, len(a[0]) - 1))

def DPAssemblyLineScheduling(
	a: list[list[float]], t: list[list[float]], e: list[int], x: list[int]
) -> tuple[float, list[int]]:
	f = [[e[0] + a[0][0]], [e[1] + a[1][0]]]
	for j in range(1, len(a[0])):
		f[0].append(min(
			f[0][j - 1] + a[0][j],
			f[1][j - 1] + t[1][j - 1] + a[0][j]
		))
		f[1].append(min(
			f[0][j - 1] + t[0][j - 1] + a[1][j],
			f[1][j - 1] + a[1][j]
		))
	return min(f[0][len(a[0]) - 1] + x[0], f[1][len(a[0]) - 1] + x[1])

# print(BinAssemblyLineScheduling(deepcopy(a), deepcopy(t), e, x))
# print(DPAssemblyLineScheduling(a, t, e, x))


len_arrs = (16, 64, 256, 1024, 4096)
algos = (BinAssemblyLineScheduling, DPAssemblyLineScheduling)
algo_names = {"BinAssemblyLineScheduling": "BIN", "DPAssemblyLineScheduling": "DP"}

def timer(N, rep = 10):
	a = [[randint(1, 15) for _ in range(N)] for _ in range(2)]
	t = [[randint(1, 15) for _ in range(N)] for _ in range(2)]
	e = [randint(1, 15), randint(1, 15)]
	x = [randint(1, 15), randint(1, 15)]

	for typename in algos:
		timesElapsed = []
		for _ in range(rep):
			aa = deepcopy(a)
			timeElapsed = time()
			typename(aa, t, e, x)
			timeElapsed = time() - timeElapsed
			timesElapsed.append(timeElapsed)

		print("%4s(%d) %3.6fs" % (
			algo_names[typename.__name__], N, sum(timesElapsed) / rep
		), end = " [")
		for te in timesElapsed:
			print("%.6f" % te, end = " ")
		print("]")
	print()

def memprofiler(N, rep = 10):
	a = [[randint(1, 15) for _ in range(N)] for _ in range(2)]
	t = [[randint(1, 15) for _ in range(N)] for _ in range(2)]
	e = [randint(1, 15), randint(1, 15)]
	x = [randint(1, 15), randint(1, 15)]

	for typename in algos:
		memsPeak = []
		for _ in range(rep):
			aa = deepcopy(a)
			tracemalloc.start()
			typename(aa, t, e, x)
			memPeak = tracemalloc.get_traced_memory()[1]
			tracemalloc.stop()
			memsPeak.append(memPeak / 1000)

		print("%4s(%d) %4.2fKB" % (
			algo_names[typename.__name__], N, sum(memsPeak) / rep
		), end = " [")
		for mp in memsPeak:
			print("%.2f" % mp, end = " ")
		print("]")
	print()

def test():
	print("Runtime Time:")
	for N in len_arrs:
		timer(N)

	print("Runtime Memory:")
	for N in len_arrs:
		memprofiler(N)

test()