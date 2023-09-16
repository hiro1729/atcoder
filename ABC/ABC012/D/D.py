n, m = map(int, input().split())
d = [[10 ** 9] * n for _ in range(n)]
for i in range(n):
	d[i][i] = 0
for _ in range(m):
	a, b, t = map(int, input().split())
	a -= 1
	b -= 1
	d[a][b] = t
	d[b][a] = t
for k in range(n):
	for i in range(n):
		for j in range(n):
			d[i][j] = min(d[i][j], d[i][k] + d[k][j])
print(min(max(d[i][j] for j in range(n)) for i in range(n)))