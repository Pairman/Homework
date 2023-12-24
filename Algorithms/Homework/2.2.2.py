from random import randint

'''top-down-mergesort'''
class TopdownMergeSort:
	size = 0
	arr, aux = None, None

	def __init__(self, arr = None):
		self.arr = arr
		if not arr:
			self.arr = [randint(0, 9) for i in range(randint(8, 16))]
		self.size = len(self.arr)
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
	def sort(self, lo = None, hi = None):
		if lo is None:
			lo = 0
		if hi is None:
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

'''bottom-up-mergesort'''
class BottomupMergeSort:
	def __init__(self, arr = None):
		super().__init__(arr)

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



# ms = TopdownMergeSort(["E", "E", "G", "M", "R", "A", "C", "E", "R", "T"])
# ms = TopdownMergeSort(["J", "I", "H", "G", "F", "E", "D", "C", "B", "A"])
ms = TopdownMergeSort(list("MERGESORTEXAMPLE"))
ms.sort()
print(ms.arr)