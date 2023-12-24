from sys import getsizeof
from random import SystemRandom
from random import shuffle
from timeit import default_timer as time
import tracemalloc

'''selection sort'''
class SelectionSort:
	size = 0
	arr = None

	def __init__(self, arr = None):
		self.arr = arr
		if not arr:
			rng = SystemRandom()
			self.arr = [rng.randint(0, 9) for i in range(rng.randint(8, 16))]
		self.size = len(self.arr)

	# Sort arr[lo:hi + 1]
	def sort(self, lo = 0, hi = None):
		if hi == None:
			hi = self.size - 1
		if lo >= hi:
			return

		# Swap with the minimum value in arr[i:hi + 1] with arr[i]
		for i in range(lo, hi + 1):
			min = i
			for j in range(i + 1, hi + 1):
				if self.arr[j] < self.arr[min]:
					min = j
			self.arr[i], self.arr[min] = self.arr[min], self.arr[i]

'''insertion sort'''
class InsertionSort(SelectionSort):
	def __init__(self, arr = None):
		super().__init__(arr)

	# Sort arr[lo:hi + 1]
	def sort(self, lo = 0, hi = None):
		if hi == None:
			hi = self.size - 1
		if lo >= hi:
			return
		# Insert arr[i] to arr[i - 1], arr[i - 2], ... if descending
		for i in range(lo, hi + 1):
			for j in reversed(range(lo + 1, i + 1)):
				if self.arr[j - 1] >= self.arr[j]:
					self.arr[j - 1], self.arr[j] = self.arr[j], self.arr[j - 1]

'''top-down mergesort'''
class TopdownMergeSort(SelectionSort):
	aux = None

	def __init__(self, arr = None):
		super().__init__(arr)
		self.aux = [0 for i in range(self.size)]

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

'''bottom-up mergesort'''
class BottomupMergeSort(TopdownMergeSort):
	def __init__(self, arr = None):
		super().__init__(arr)
		self.aux

	# Sort arr
	def sort(self):
		# Split the array in sz lengthed segments
		# And double sz for the next time
		sz = 1
		while sz < self.size:
			# Merge each two adjaent sz lengthed segments in arr
			for lo in range(0, self.size - sz, sz + sz):
				# Merge arr[lo:lo + sz] with arr[lo + sz + 1:lo + sz + sz +1]
				# Overflow prevention with min(lo + sz + sz - 1, self.size - 1)
				self.merge(lo, lo + sz - 1, min(lo + sz + sz - 1, self.size - 1))
			sz += sz

'''random quick sort'''
class QuickSort(SelectionSort):
	def __init__(self, arr = None, shuff = 0):
		super().__init__(arr)
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

'''dijkstra three-partition quick sort'''
class ThreeWayQuickSort(SelectionSort):
	def __init__(self, arr = None, shuff = 0):
		super().__init__(arr)
		# Shuffle to minimize influence from arr's orderness
		if shuff:
			shuffle(self.arr)

	# Partition arr[lo:hi + 1]
	def partition(self, lo, hi):
		# Take arr[lo] as reference v
		lt, i, gt, v = lo, lo + 1, hi, self.arr[lo]

		# Partition until arr[lo:lt - 1] <= arr[lt:gt] = v <= arr[gt + 1, hi + 1]
		while i <= gt:
			# Pick arr[i] < v
			if self.arr[i] < v:
				# Swap two picked values so that the arr[i] will be in arr[lo:lt]
				self.arr[i], self.arr[lt] = self.arr[lt], self.arr[i]
				lt += 1
				i += 1
			# Pick arr[i] > v
			elif self.arr[i] > v:
				# Swap two picked values so that the arr[i] will be in arr[gt + 1:hi + 1]
				self.arr[i], self.arr[gt] = self.arr[gt], self.arr[i]
				gt -= 1
			# Pick arr[i] == v
			else:
				# Don't swap if arr[i] == v so that all arr[lt:gt] == v
				i += 1
		return lt, gt

	# Sort arr[lo:hi + 1]
	def sort(self, lo = 0, hi = None):
		if hi == None:
			hi = self.size - 1
		if lo >= hi:
			return

		# Partition and let arr[j] be reference
		lt, gt = self.partition(lo, hi)

		# Sort arr[lo:lt]
		self.sort(lo, lt - 1)
		# Sort arr[gt + 1:hi + 1]
		self.sort(gt + 1, hi)

len_arrs = (16, 64, 256, 1024, 4096, 16384)
sort_algos = (InsertionSort, TopdownMergeSort, BottomupMergeSort, QuickSort, ThreeWayQuickSort)
sort_names = {"InsertionSort": "IS", "TopdownMergeSort": "TDM", "BottomupMergeSort": "BUM", "QuickSort": "RQ", "ThreeWayQuickSort": "QD3P"}

def timer(N, l = None, shuff = 1, rep = 10, innershuff = 1):
	if not l:
		l = list(range(N))
	if shuff:
		shuffle(l)

	for typename in sort_algos:
		timesElapsed = []
		for t in range(rep):
			if typename in (QuickSort, ThreeWayQuickSort):
				s = typename(l.copy(), innershuff)
			else:
				s = typename(l.copy())

			timeElapsed = time()
			s.sort()
			timeElapsed = time() - timeElapsed
			timesElapsed.append(timeElapsed)

		print("%4s(%d) %3.6fs" % (sort_names[typename.__name__], N, sum(timesElapsed) / rep), end = " [")
		for te in timesElapsed:
			print("%.6f" % te, end = " ")
		print("]")
	print()

def spaceprofiler(N):
	l = list(range(N))

	for typename in sort_algos:
		if typename in (QuickSort, ThreeWayQuickSort):
			s = typename(l.copy(), 0)
		else:
			s = typename(l.copy())

		spaceUsed = getsizeof(s.arr)
		if typename in (TopdownMergeSort, BottomupMergeSort):
			spaceUsed += getsizeof(s.aux)

		spaceUsed /= 1000

		print("%4s(%d) %4.2fKB" % (sort_names[typename.__name__], N, spaceUsed))
	print()

def memprofiler(N, l = None, shuff = 1, rep = 10, innershuff = 1):
	if not l:
		l = list(range(N))
	if shuff:
		shuffle(l)

	for typename in sort_algos:
		memsPeak = []
		for t in range(rep):
			if typename in (QuickSort, ThreeWayQuickSort):
				s = typename(l.copy(), innershuff)
			else:
				s = typename(l.copy())

			tracemalloc.start()
			s.sort()
			memPeak = tracemalloc.get_traced_memory()[1]
			tracemalloc.stop()
			memsPeak.append(memPeak / 1000)

		print("%4s(%d) %4.2fKB" % (sort_names[typename.__name__], N, sum(memsPeak) / rep), end = " [")
		for mp in memsPeak:
			print("%.2f" % mp, end = " ")
		print("]")
	print()

def q0():
	print("Runtime Time:")
	for N in len_arrs:
		timer(N)

	print("Initialization Memory:")
	for N in len_arrs:
		spaceprofiler(N)

	print("Runtime Memory:")
	for N in len_arrs:
		memprofiler(N)

def q1(N = 1024):
	print("Ascending:")
	l = list(range(N))
	timer(N, l, shuff = 0)
	spaceprofiler(N)
	memprofiler(N, l, shuff = 0, innershuff = 0)

	print("Constant:")
	l = [0 for i in range(N)]
	timer(N, l, shuff = 0)
	spaceprofiler(N)
	memprofiler(N, l, shuff = 0, innershuff = 0)

q0()