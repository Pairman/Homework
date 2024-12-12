def MaxHeap(arr: list):
	def swim(arr, i):
		p, l, r = i, 2 * i + 1, 2 * i + 2
		if l < len(arr) and arr[l] > arr[p]:
			p = l
		if r < len(arr) and arr[r] > arr[p]:
			p = r
		if p != i:
			arr[i], arr[p] = arr[p], arr[i]
			swim(arr, p)
	for i in range(len(arr) // 2 - 1, -1, -1):
		swim(arr, i)

from random import randint
from math import log2
arr = [randint(0, 9) for _ in range(randint(0, 16))]
print("ORIG", arr)
MaxHeap(arr)
print("HEAP", arr)
for i, v in enumerate(arr):
	print(f"{' ' * 2 ** int(log2(i + 1)) }{v}")

"""
ORIG [6, 2, 6, 3, 8, 6, 0, 4, 3, 6, 5, 2, 9]
HEAP [9, 8, 6, 4, 6, 6, 0, 3, 3, 2, 5, 2, 6]
 9
  8
  6
    4
    6
    6
    0
        3
        3
        2
        5
        2
        6
"""