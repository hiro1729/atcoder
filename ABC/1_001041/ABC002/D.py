n, m = map(int, input().split())
r = [[False] * n for _ in range(n)]
for i in range(m):
	x, y = map(int, input().split())
	x -= 1
	y -= 1
	r[x][y] = True
	r[y][x] = True
ans = 0
for b in range(1 << n):
	t = []
	for i in range(n):
		if (b >> i) & 1:
			t.append(i)
	f = True
	for a in t:
		for b in t:
			if a != b:
				f &= r[a][b]
	if f:
		ans = max(ans, len(t))
print(ans)