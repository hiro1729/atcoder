from atcoder.maxflow import *
n, k, m = map(int, input().split())
g = MFGraph(n + 1)
for i in list(map(int, input().split())):
	g.add_edge(i, n, 1)
for _ in range(m):
	u, v = map(int, input().split())
	g.add_edge(u, v, 1)
	g.add_edge(v, u, 1)
print(g.flow(0, n))