from sortedcontainers import SortedSet

N, Q = map(int, input().split())
edges = []
for _ in range(Q):
	L, R, C = map(int, input().split())
	edges.append((C, L - 1, R - 1))
edges.sort()
st = SortedSet(list(range(N - 1))) # 頂点 j と j + 1 がつながっていないならば集合に含まれるようにする
ans = 0
for C, L, R in edges:
	# L, …, R - 1 を削除する
	cnt = 0
	while True:
		bs = st.bisect_left(L)
		if bs < len(st) and st[bs] < R:
			cnt += 1
			st.pop(bs)
		else:
			break
	ans += (cnt + 1) * C
print(ans if len(st) == 0 else -1)