from random import shuffle
from timeit import default_timer as time
import tracemalloc

class TopdownMergeSort():
	size = 0
	arr = aux = None

	def __init__(self, arr = None):
		self.arr = arr
		self.size = len(self.arr)
		self.aux = [0] * self.size

	# Merge sorted arr[lo:mid + 1] with arr[mid + 1:hi + 1]
	def merge(self, lo, mid, hi):
		# Copy arr[lo:hi + 1] to aux[lo:hi + 1]
		self.aux[lo:hi + 1] = self.arr[lo: hi + 1]

		# Pick values orderly from aux[lo:hi + 1] back to arr[lo:hi + 1]
		i, j = lo, mid + 1
		for k in range(lo, hi + 1):
			# If arr[lo:mid] is all picked up, pick aux[j]
			if i > mid:
				self.arr[k] = self.aux[j]
				j += 1
			# If arr[mid + 1:hi] is all picked up, pick aux[i]
			elif j > hi:
				self.arr[k] = self.aux[i]
				i += 1
			# Pick aux[j] if smaller
			elif self.aux[j] < self.aux[i]:
				self.arr[k] = self.aux[j]
				j += 1
			# Pick aux[i] if smaller
			else:
				self.arr[k] = self.aux[i]
				i += 1

	# Sort arr[lo:hi + 1]
	def sort(self, lo = 0, hi = None):
		if hi == None:
			hi = self.size - 1
		if lo >= hi:
			return

		# Split arr[lo:hi + 1] by half
		mid = lo + (hi - lo) // 2

		# Sort arr[lo:mid + 1]
		self.sort(lo, mid)
		# Sort arr[mid + 1:hi + 1]
		self.sort(mid + 1, hi)

		# Merge sorted arr[lo:mid + 1] with arr[mid + 1:hi + 1] if left half has value greater than one in right half
		if self.arr[mid] >= self.arr[mid + 1]:
			self.merge(lo, mid, hi)

class QuickSort():
	size = 0
	arr = None
	def __init__(self, arr = None, shuff = 0):
		self.arr = arr
		self.size = len(self.arr)
		# Shuffle to minimize influence from arr's orderness
		if shuff:
			shuffle(self.arr)

	# Partition arr[lo:hi + 1]
	def partition(self, lo, hi):
		i, j = lo + 1, hi

		# Take arr[lo] as reference
		v = self.arr[lo]

		# Partition until arr[lo:j] <= arr[j] = v <= arr[j + 1, hi + 1]
		while True:
			# Pick arr[i] >= v
			# Note that iteration starts from arr[lo + 1]
			while i < hi and self.arr[i] <= v:
				i += 1
			# Pick arr[j] <= v
			while j > lo and self.arr[j] >= v:
				j -= 1
			# Stop when i >= j a.k.a. arr[lo:j] <= v or v <= arr[j + 1, hi + 1] thus unable to pick
			if i >= j:
				break
			# Swap two picked values so that the new arr[i] <= v <= arr[j]
			self.arr[i], self.arr[j] = self.arr[j], self.arr[i]
		# Swap arr[lo] with arr[j]
		self.arr[lo], self.arr[j] = self.arr[j], self.arr[lo]
		return j

	# Sort arr[lo:hi + 1]
	def sort(self, lo = 0, hi = None):
		if hi == None:
			hi = self.size - 1
		if lo >= hi:
			return

		# Partition and let arr[j] be reference
		j = self.partition(lo, hi)

		# Sort arr[lo:j - 1]
		self.sort(lo, j - 1)
		# Sort arr[j + 1:hi + 1]
		self.sort(j + 1, hi)


len_arrs = (16, 64, 256, 1024, 4096)
sort_algos = (TopdownMergeSort, QuickSort)
sort_names = {"TopdownMergeSort": "TM", "QuickSort": "RQ"}

def timer(N, l = None, shuff = 1, rep = 10, innershuff = 1):
	if not l:
		l = list(range(N))
	if shuff:
		shuffle(l)

	for typename in sort_algos:
		timesElapsed = []
		for t in range(rep):
			if typename in (QuickSort, ):
				s = typename(l.copy(), innershuff)
			else:
				s = typename(l.copy())

			timeElapsed = time()
			s.sort()
			timeElapsed = time() - timeElapsed
			timesElapsed.append(timeElapsed)

		print("%4s(%d) %3.6fs" % (
			sort_names[typename.__name__], N, sum(timesElapsed) / rep
		), end = " [")
		for te in timesElapsed:
			print("%.6f" % te, end = " ")
		print("]")
	print()

def memprofiler(N, l = None, shuff = 1, rep = 10, innershuff = 1):
	if not l:
		l = list(range(N))
	if shuff:
		shuffle(l)

	for typename in sort_algos:
		memsPeak = []
		for t in range(rep):
			if typename in (QuickSort, ):
				s = typename(l.copy(), innershuff)
			else:
				s = typename(l.copy())

			tracemalloc.start()
			s.sort()
			memPeak = tracemalloc.get_traced_memory()[1]
			tracemalloc.stop()
			memsPeak.append(memPeak / 1000)

		print("%4s(%d) %4.2fKB" % (
			sort_names[typename.__name__], N, sum(memsPeak) / rep
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
  TM(16)   0.000028s [0.000044 0.000028 0.000027 0.000027 0.000025 0.000025 0.000026 0.000025 0.000025 0.000026 ]
  RQ(16)   0.000019s [0.000040 0.000019 0.000017 0.000016 0.000017 0.000018 0.000016 0.000016 0.000018 0.000017 ]

  TM(64)   0.000162s [0.000173 0.000140 0.000155 0.000139 0.000149 0.000139 0.000155 0.000184 0.000186 0.000196 ]
  RQ(64)   0.000143s [0.000124 0.000114 0.000116 0.000139 0.000112 0.000118 0.000125 0.000178 0.000199 0.000202 ]

  TM(256)  0.001155s [0.001298 0.001045 0.001007 0.001141 0.001048 0.001252 0.001064 0.001003 0.000994 0.001696 ]
  RQ(256)  0.000648s [0.000656 0.000631 0.000659 0.000627 0.000653 0.000693 0.000634 0.000631 0.000643 0.000652 ]

  TM(1024) 0.004829s [0.005096 0.005096 0.006257 0.005884 0.005562 0.005281 0.004710 0.003758 0.003722 0.002925 ]
  RQ(1024) 0.002008s [0.002009 0.002197 0.002468 0.001836 0.001914 0.001863 0.002089 0.001889 0.001875 0.001944 ]

  TM(4096) 0.021988s [0.015828 0.018611 0.014831 0.020057 0.024141 0.025222 0.025066 0.024909 0.025865 0.025353 ]
  RQ(4096) 0.016086s [0.017381 0.015687 0.016735 0.015547 0.017719 0.016903 0.013657 0.015605 0.016256 0.015373 ]

Runtime Memory:
  TM(16)   0.26KB [0.26 0.26 0.26 0.26 0.26 0.26 0.26 0.26 0.26 0.26 ]
  RQ(16)   0.00KB [0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 ]

  TM(64)   1.02KB [1.02 1.02 1.02 1.02 1.02 1.02 1.02 1.02 1.02 1.02 ]
  RQ(64)   0.00KB [0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 ]

  TM(256)  4.10KB [4.10 4.10 4.10 4.10 4.10 4.10 4.10 4.10 4.10 4.10 ]
  RQ(256)  0.00KB [0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 ]

  TM(1024) 16.48KB [16.48 16.48 16.48 16.48 16.48 16.48 16.48 16.48 16.48 16.48 ]
  RQ(1024) 1.22KB [1.18 1.09 1.18 1.34 1.25 1.31 1.15 1.15 1.25 1.28 ]

  TM(4096) 65.63KB [65.63 65.63 65.63 65.63 65.63 65.63 65.63 65.63 65.63 65.63 ]
  RQ(4096) 1.61KB [1.73 1.70 1.44 1.70 1.70 1.60 1.54 1.60 1.70 1.44 ]
"""