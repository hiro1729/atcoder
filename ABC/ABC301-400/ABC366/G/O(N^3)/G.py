N, M = map(int, input().split())
g = [[0] * N for _ in range(N)]
for _ in range(M):
	u, v = map(int, input().split())
	u -= 1
	v -= 1
	g[u][v] = 1
	g[v][u] = 1
d_1 = [0] * N
c = [0] * N
for i in range(N):
	k = -1
	for j in range(N):
		if g[j][i] == 1 and all(g[j][k] == 0 for k in range(i)):
			k = j
			break
	if k == -1:
		continue
	d_1[i] = 1
	g[i], g[k] = g[k], g[i]
	for j in range(N):
		if i != j and g[j][i] == 1:
			for k in range(i, N):
				g[j][k] ^= g[i][k]
for i in range(N):
	if sum(g[i]) == 1:
		print("No")
		exit()
for i in range(N):
	if d_1[i] == 0:
		c[i] = 1 << i
for i in range(N):
	for j in range(N):
		if d_1[j] == 1 and g[i][j] == 1:
			for k in range(N):
				if g[i][k] == 1:
					c[j] ^= c[k]
print("Yes")
print(*c)