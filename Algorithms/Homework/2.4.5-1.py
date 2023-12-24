class MaxPQ_BinHeap_BinTree:
	class __Node:
		p = l = r = v = None

	def __init__(self):
		self.__size, self.__root, self.__tail = 0, self.__Node(), self.__Node()

	def __settail(self, k):
		pass

	def __swim(self, k):
		while k != self.__root and k.p.v < k.v:
			k.p.v, k.v = k.v, k.p.v
			k = k.p

	def __sink(self, k):
		while (j := k.l):
			if k.r and j.v < k.r.v:
				j += 1
			if k.v >= j.v:
				break
			k.v, j.v = j.v, k.v
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

l = MaxPQ_BinHeap_BinTree()
for v in "EASYQUESTION":
	l.push(v)
print(l)