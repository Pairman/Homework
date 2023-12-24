from random import SystemRandom
from random import shuffle

'''binary key sort'''
class BinKeySort:
	size = 0
	arr = None

	def __init__(self, arr):
		self.arr = arr
		self.size = len(arr)

	def sort(self):
		i, j = 0, 1
		while j < self.size:
			if self.arr[i] > self.arr[j]:
				self.arr[i], self.arr[j] = self.arr[j], self.arr[i]
				i += 1
				j += 1
			elif self.arr[i] < self.arr[j]:
				i += 1
			else:
				j += 1
			print(i, j, self.arr)