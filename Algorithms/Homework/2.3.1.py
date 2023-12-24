from random import SystemRandom
from random import shuffle

'''random quick sort'''
class QuickSort:
	size = 0
	arr = None

	def __init__(self, arr = None, shuff = 0):
		self.arr = arr
		if not arr:
			rng = SystemRandom()
			self.arr = [rng.randint(0, 9) for i in range(rng.randint(8, 16))]
		self.size = len(self.arr)
		if shuff:
			shuffle(self.arr)

	# Partition arr[lo:hi + 1]
	def partition(self, lo, hi, depth):
		i, j = lo + 1, hi

		# Take arr[lo] as reference
		v = self.arr[lo]

		print("%spart(%2d, %2d)    %s" % (" " * depth, lo, hi, " " * (8 - depth)), self.arr)

		# Partition until arr[lo:j] <= arr[j] = v <= arr[j + 1, hi + 1]
		while True:
			# Pick arr[i] >= v
			# Note that iteration starts from arr[lo + 1]
			while i < hi and self.arr[i] < v:
				i += 1
			# Pick arr[j] <= v
			while j > lo and self.arr[j] > v:
				j -= 1
			if i >= j:
				break
			self.arr[i], self.arr[j] = self.arr[j], self.arr[i]
			print("%s     %2d, %2d     %s" % (" " * depth, i, j, " " * (8 - depth)), self.arr)

		# Swap arr[lo] with arr[j]
		self.arr[lo], self.arr[j] = self.arr[j], self.arr[lo]


		return j

	# Sort arr[lo:hi + 1]
	def sort(self, lo = 0, hi = None, depth = 0):
		if hi == None:
			hi = self.size - 1
		if lo >= hi:
			return

		# Partition and let arr[j] be reference
		j = self.partition(lo, hi, depth = depth)

		print("%ssort(%2d, %2d, %2d)%s" % (" " * depth, lo, j, hi, " " * (8 - depth)), self.arr)
		# Sort arr[lo:j - 1]
		self.sort(lo, j - 1, depth = depth + 1)
		# Sort arr[j + 1:hi + 1]
		self.sort(j + 1, hi, depth = depth + 1)

# qs = QuickSort([2,9,4,1,6,3,8,5,7])
qs = QuickSort([2,8,4,1,6,3,5,7])
qs.sort()
