import math

class LCA:
	def __init__(self, n):
		self.n = n
		self.ln = int(math.log2(self.n)) + 2
		self.depth = [0] * self.n
		self.dist = [0] * self.n
		self.anc = [[-1] * self.n for _ in range(self.ln)]
		self.edges = [[] for _ in range(self.n)]
	def add_edge(self, u, v, w = 1):
		self.edges[u].append((v, w))
		self.edges[v].append((u, w))
	def build(self, rt = 0):
		st = [rt]
		while st:
			cr = st.pop()
			for nx, w in self.edges[cr]:
				if self.anc[0][nx] != cr and self.anc[0][cr] != nx:
					self.anc[0][nx] = cr
					self.depth[nx] = self.depth[cr] + 1
					self.dist[nx] = self.dist[cr] + w
					st.append(nx)
		for k in range(1, self.ln):
			for i in range(self.n):
				if self.anc[k - 1][i] == -1:
					self.anc[k][i] = -1
				else:
					self.anc[k][i] = self.anc[k - 1][self.anc[k - 1][i]]
	def lca(self, u, v):
		if self.depth[u] > self.depth[v]:
			u, v = v, u
		for k in range(self.ln - 1, -1, -1):
			if ((self.depth[v] - self.depth[u]) >> k) & 1:
				v = self.anc[k][v]
		if u == v:
			return u
		for k in range(self.ln - 1, -1, -1):
			if self.anc[k][u] != self.anc[k][v]:
				u = self.anc[k][u]
				v = self.anc[k][v]
		return self.anc[0][u]
	def distance(self, u, v):
		return self.dist[u] + self.dist[v] - 2 * self.dist[self.lca(u, v)]

N = int(input())
g = LCA(N)
for _ in range(N - 1):
	x, y = map(int, input().split())
	x -= 1
	y -= 1
	g.add_edge(x, y)
g.build()
Q = int(input())
for _ in range(Q):
	a, b = map(int, input().split())
	a -= 1
	b -= 1
	print(g.distance(a, b) + 1)