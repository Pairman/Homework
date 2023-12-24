class MaxPQ_BinHeap_Arr:
	def __init__(self, arr = []):
		self.__size, self.__arr = len(arr), [None] + sorted(arr, reverse = 1)

	def __swim(self, k):
		while k > 1 and self.__arr[k // 2] < self.__arr[k]:
			self.__arr[k // 2], self.__arr[k] = self.__arr[k], self.__arr[k // 2]
			k = k // 2

	def __sink(self, k):
		while (j := k * 2) <= self.__size:
			if j < self.__size and self.__arr[j] < self.__arr[j + 1]:
				j += 1
			if self.__arr[k] >= self.__arr[j]:
				break
			self.__arr[k], self.__arr[j] = self.__arr[j], self.__arr[k]
			k = j

	def push(self, val):
		self.__arr.append(val)
		self.__size += 1
		self.__swim(self.__size)

	def pop(self):
		self.__arr[1], self.__arr[self.__size] = self.__arr[self.__size], self.__arr[1]
		self.__size -= 1
		maxv = self.__arr.pop()
		self.__sink(1)
		return maxv

	def __repr__(self):
		return str(self.__size) + ", " + str(self.__arr)

l = MaxPQ_BinHeap_Arr()
for v in "EASYQUESTION":
	l.push(v)
print(l)