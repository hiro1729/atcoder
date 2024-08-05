from atcoder.lazysegtree import LazySegTree

N, Q = map(int, input().split())
edges = []
for _ in range(Q):
	L, R, C = map(int, input().split())
	edges.append((C, L - 1, R - 1))
edges.sort()
lseg = LazySegTree(op = lambda a, b: (a[0] + b[0], a[1] + b[1]),
                   e = (0, 0),
                   mapping = lambda f, x: (x[1] * f, x[1]) if f != -1 else x,
                   composition = lambda f, g: g if f == -1 else f,
                   id_ = -1,
                   v = [(1, 1)] * (N - 1))
ans = 0
for C, L, R in edges:
	cnt = lseg.prod(L, R)[0]
	lseg.apply(L, R, 0)
	ans += (cnt + 1) * C
print(ans if lseg.all_prod()[0] == 0 else -1)