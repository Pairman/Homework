def MaxK(arr: list, i: int, j: int, k: int) -> list[int]:
	l = j - i
	k = min(k, l)
	if k == 0:
		return []
	if k == 1:
		return [arr[max(i, 0)]]
	else:
		m = (i + j) // 2
		it1, it2 = MaxK(arr, i, m, k), MaxK(arr, m, j, k)
		ret = []
		i, j = 0, 0
		for _ in range(k):
			if i < len(it1) and j < len(it2):
				u, v = it1[i], it2[j]
				if u >= v:
					ret.append(u)
					i += 1
				else:
					ret.append(v)
					j += 1
			elif i < len(it1):
				ret.append(it1[i])
				i += 1
			else:
				ret.append(it2[j])
				j += 1
		return ret

from random import randint
arr = [randint(0, 9) for _ in range(randint(0, 16))]
print("ORIG", arr)
arr = MaxK(arr, 0, len(arr), len(arr))
print("MAXK", arr)

"""
ORIG [5, 9, 8, 8, 3, 7]
MAXK [9, 8, 8, 7, 5, 3]
"""