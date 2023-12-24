class MaxPQ_Arr:
	def __init__(self, arr = []):
		self.__arr = arr

	def push(self, val):
		self.__arr.append(val)

	def pop(self):
		if not len(self.__arr):
			return
		maxi = 0
		for i in range(1, len(self.__arr)):
			if self.__arr[i] > self.__arr[maxi]:
				maxi = i
		return self.__arr.pop(maxi)

class MaxPQ_OrdArr:
	def __init__(self, arr = []):
		self.__arr = sorted(arr)

	def push(self, val):
		i = gt = 0
		for i in range(0, len(self.__arr)):
			if self.__arr[i] > val:
				gt = 1
				break
		if gt:
			self.__arr.insert(i, val)
		else:
			self.__arr.append(val)

	def pop(self):
		if not len(self.__arr):
			return
		return self.__arr.pop()

class MaxPQ_LL:
	class __Node:
		val = next = None

	def __init__(self, arr = []):
		self.__head, self.__tail = self.__Node(), self.__Node()
		node = self.__head
		for val in arr:
			node.next = self.__Node()
			node.next.val = val
			node = node.next
		node.next = self.__tail

	def push(self, val):
		node, next = self.__Node(), self.__head.next
		node.val, self.__head.next, node.next = val, node, next

	def pop(self):
		if self.__head.next == self.__tail:
			return
		maxn = (maxl := (last := self.__head)).next
		while (last.next != self.__tail):
			if maxn.val < last.next.val:
				maxl, maxn = last, last.next
			last = last.next
		maxl.next, maxv = maxn.next, maxn.val
		del maxn
		return maxv

class MaxPQ_OrdLL:
	class __Node:
		val = next = None

	def __init__(self, arr = []):
		self.__head, self.__tail = self.__Node(), self.__Node()
		node = self.__head
		for val in sorted(arr, reverse = 1):
			node.next = self.__Node()
			node.next.val = val
			node = node.next
		node.next = self.__tail

	def push(self, val):
		node = (last := self.__head).next
		while (node != self.__tail):
			if node.val <= val:
				break
			last, node = last.next, node.next
		next = node
		node = self.__Node()
		last.next, node.next, node.val = node, next, val

	def pop(self):
		if self.__head.next == self.__tail:
			return
		self.__head.next, maxv = (maxn := self.__head.next).next, maxn.val
		del maxn
		return maxv