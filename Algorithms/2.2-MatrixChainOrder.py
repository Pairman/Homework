from random import randint

def GreedyMatrixChainOrder(dims):
	n = len(dims) - 1
	dims = dims[:]
	cost = 0
	splits = [i for i in range(n)]
	# while mergable
	while len(dims) > 2:
		# select the max dim
		i_max = max(enumerate(
			dims[i] * dims[i + 1] for i in range(1, len(dims) - 1)
		), key=lambda v: v[1])[0] + 1
		# calculate cost and merge
		cost += dims[i_max - 1] * dims[i_max] * dims[i_max + 1]
		splits[i_max - 1] = (splits[i_max - 1], splits.pop(i_max))
		dims.pop(i_max)
	return cost, splits.pop()

def DPMatrixChainOrder(dims):
	n = len(dims) - 1
	# initialize costs of length 1 chains to 0
	costs = [[0] * n for _ in range(n)]
	splits = [[0] * n for _ in range(n)]
	# for length 2 to n chains
	for l in range(2, n + 1):
		# choose i and j
		for i in range(n - l + 1):
			j = i + l - 1
			costs[i][j] = float("inf")
			# for split points k between i and j
			for k in range(i, j):
				# cost = left_cost + right_cost + left_mul_right_cost
				cost = (
					costs[i][k] + costs[k + 1][j] +
					dims[i] * dims[k + 1] * dims[j + 1]
				)
				# update split point and cost if smaller
				if cost < costs[i][j]:
					costs[i][j] = cost
					splits[i][j] = k
	# return total cost and split points
	return costs[0][n - 1], (f := lambda s, i, j: i if i == j else (
		f(s, i, s[i][j]), f(s, s[i][j] + 1, j)
	))(splits, 0, n - 1)

dims = [30, 35, 15, 5, 10, 20, 25]
print("DIMS  ", dims)
print("GREEDY", GreedyMatrixChainOrder(dims))
print("DP    ", DPMatrixChainOrder(dims))

"""
DIMS   [30, 35, 15, 5, 10, 20, 25]
GREEDY (35125, ((0, 1), (2, (3, (4, 5)))))
DP     (15125, ((0, (1, 2)), ((3, 4), 5)))
"""