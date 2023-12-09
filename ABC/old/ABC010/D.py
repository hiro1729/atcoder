from atcoder.maxflow import MFGraph
N, G, E = map(int, input().split())
p = list(map(int, input().split()))
g = MFGraph(N + 1)
for i in p:
	g.add_edge(i, N, 1)
for _ in range(E):
	u, v = map(int, input().split())
	g.add_edge(u, v, 1)
	g.add_edge(v, u, 1)
print(g.flow(0, N))