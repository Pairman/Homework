from random import randint
from timeit import default_timer as time
import tracemalloc

def BetterBruteForceMaxSubarr(arr: list, l: int, h: int) -> tuple:
	bl, bh, ms = -1, -1, float("-inf")
	for i in range(l, h):
		s = 0
		for j in range(i, h):
			s += arr[j]
			if s > ms:
				bl, bh, ms = i, j, s
	return bl, bh + 1, ms

def DivideConquerMaxSubarr(arr: list, l: int, h: int) -> tuple:
	def cross(arr, l, m, h):
		ls = rs = float("-inf")
		s = 0
		for i in range(m - 1, l - 1, -1):
			s += arr[i]
			if s > ls:
				ls = s
				l = i
		s = 0
		for i in range(m, h):
			s += arr[i]
			if s > rs:
				rs = s
				h = i
		return l, h + 1, ls + rs
	if h - l == 1:
		return (l, h, arr[l])
	m = (l + h) // 2
	return max((
		DivideConquerMaxSubarr(arr, l, m),
		DivideConquerMaxSubarr(arr, m, h),
		cross(arr, l, m, h)
	), key = lambda r: r[2])

# arr = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
# print(arr)
# print(DivideConquerMaxSubarr(arr, 0, len(arr)))
# print(BetterBruteForceMaxSubarr(arr, 0, len(arr)))

len_arrs = (16, 64, 256, 1024, 4096)
algos = (BetterBruteForceMaxSubarr, DivideConquerMaxSubarr)
algo_names = {"BetterBruteForceMaxSubarr": "BF", "DivideConquerMaxSubarr": "DC"}

def timer(N, l = None, rep = 10):
	if not l:
		l = [randint(-16, 15) for i in range(N)]

	for typename in algos:
		timesElapsed = []
		for t in range(rep):
			timeElapsed = time()
			typename(l, 0, N)
			timeElapsed = time() - timeElapsed
			timesElapsed.append(timeElapsed)

		print("%4s(%d) %3.6fs" % (
			algo_names[typename.__name__], N, sum(timesElapsed) / rep
		), end = " [")
		for te in timesElapsed:
			print("%.6f" % te, end = " ")
		print("]")
	print()

def memprofiler(N, l = None, rep = 10):
	if not l:
		l = [randint(-16, 15) for i in range(N)]

	for typename in algos:
		memsPeak = []
		for t in range(rep):
			tracemalloc.start()
			typename(l, 0, N)
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

"""
Runtime Time:
  BF(16)   0.000007s [0.000011 0.000008 0.000007 0.000007 0.000007 0.000007 0.000007 0.000007 0.000007 0.000007 ]
  DC(16)   0.000090s [0.000716 0.000022 0.000022 0.000022 0.000020 0.000020 0.000021 0.000020 0.000020 0.000020 ]

  BF(64)   0.000077s [0.000085 0.000074 0.000073 0.000077 0.000075 0.000077 0.000079 0.000076 0.000077 0.000080 ]
  DC(64)   0.000094s [0.000110 0.000090 0.000088 0.000102 0.000097 0.000092 0.000088 0.000093 0.000088 0.000088 ]

  BF(256)  0.001330s [0.001339 0.001345 0.001322 0.001335 0.001286 0.001325 0.001411 0.001305 0.001346 0.001288 ]
  DC(256)  0.000388s [0.000412 0.000390 0.000385 0.000383 0.000388 0.000383 0.000382 0.000388 0.000387 0.000385 ]

  BF(1024) 0.023849s [0.024533 0.024145 0.023711 0.023736 0.023782 0.023766 0.023686 0.023677 0.023695 0.023758 ]
  DC(1024) 0.001773s [0.001871 0.001773 0.001769 0.001850 0.001759 0.001740 0.001743 0.001745 0.001736 0.001747 ]

  BF(4096) 0.395264s [0.391077 0.388142 0.404357 0.412922 0.397195 0.392226 0.393791 0.390864 0.389659 0.392405 ]
  DC(4096) 0.007429s [0.007592 0.007403 0.007391 0.007467 0.007409 0.007421 0.007429 0.007396 0.007409 0.007373 ]

Runtime Memory:
  BF(16)   0.13KB [0.13 0.13 0.13 0.13 0.13 0.13 0.13 0.13 0.13 0.13 ]
  DC(16)   0.88KB [0.88 0.88 0.88 0.88 0.88 0.88 0.88 0.88 0.88 0.88 ]

  BF(64)   0.13KB [0.13 0.13 0.13 0.13 0.13 0.13 0.13 0.13 0.13 0.13 ]
  DC(64)   1.20KB [1.20 1.20 1.20 1.20 1.20 1.20 1.20 1.20 1.20 1.20 ]

  BF(256)  0.13KB [0.13 0.13 0.13 0.13 0.13 0.13 0.13 0.13 0.13 0.13 ]
  DC(256)  1.52KB [1.52 1.52 1.52 1.52 1.52 1.52 1.52 1.52 1.52 1.52 ]

  BF(1024) 0.27KB [0.27 0.27 0.27 0.27 0.27 0.27 0.27 0.27 0.27 0.27 ]
  DC(1024) 2.70KB [2.70 2.70 2.70 2.70 2.70 2.70 2.70 2.70 2.70 2.70 ]

  BF(4096) 0.24KB [0.24 0.24 0.24 0.24 0.24 0.24 0.24 0.24 0.24 0.24 ]
  DC(4096) 3.18KB [3.18 3.18 3.18 3.18 3.18 3.18 3.18 3.18 3.18 3.18 ]

"""