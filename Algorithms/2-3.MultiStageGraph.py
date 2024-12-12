from io import StringIO

class Edge:
	def __init__(self, v, w, weight):
		self.v, self.w, self.weight = v, w, weight

	def __repr__(self):
		return f"<{self.v}-{self.w}|{self.weight}>"

	def other(self, v):
		return self.w if v == self.v else self.v if v == self.w else None

class MSGraph:
	def __init__(self, file: StringIO):
		while not (line := file.readline().strip()):
			pass
		(self.V, E), self.E, self.edges = map(int, line.split()), 0, []
		self.adj = [{} for _ in range(self.V)]
		for line in file:
			if line := line.strip():
				self.addedge(*map(int, line.split()))

	def __repr__(self):
		return f"""{self.V} {self.E}\n{"\n".join(
			f"{v}: {' '.join(map(str, self.adj[v].values()))}"
			for v in range(self.V)
		)}"""

	def weight(self, v, w):
		return self.adj[v][w]

	def addedge(self, v, w, weight):
		self.adj[v][w] = Edge(v, w, weight)
		self.edges.append(self.adj[v][w])
		self.E += 1

	def shortest(self):
		dist, path = [float("inf")] * self.V, [0] * self.V
		dist[0] = 0
		for v in range(self.V - 1):
			for w, e in self.adj[v].items():
				if (d := dist[v - 1] + e.weight) < dist[w - 1]:
					dist[w - 1], path[w - 1] = d, v
		spath, v = [self.V], self.V - 1
		while v:
			spath.append(v)
			v = path[v - 1]
		spath.append(0)
		spath.reverse()
		return dist[self.V - 1], spath

print(MSGraph(StringIO("""
15 30
0 1 5\n\n0 2 3
1 3 1\n1 4 3\n1 5 6\n\n2 4 8\n2 5 7\n2 6 6
3 7 6\n3 8 8\n\n4 7 3\n4 8 5\n\n5 8 3\n5 9 3\n\n6 8 8\n6 9 4
7 10 2\n7 11 2\n\n8 11 1\n8 12 2\n\n9 11 3\n9 12 3
10 13 3\n10 14 5\n\n11 13 5\n11 14 2\n\n12 13 6\n12 14 6
13 15 4\n\n14 15 3
""")).shortest())

"""
(15, [0, 1, 4, 7, 11, 14, 15])
"""