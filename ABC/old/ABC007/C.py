from collections import deque
R, C = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
sy -= 1
sx -= 1
gy -= 1
gx -= 1
c = [list(input()) for _ in range(R)]
d = [[-1] * C for _ in range(R)]
d[sy][sx] = 0
q = deque([(sy, sx)])
while q:
	x, y = q.popleft()
	for nx, ny in [(x + 1, y), (x, y + 1), (x - 1, y), (x, y - 1)]:
		if c[nx][ny] == '.' and d[nx][ny] == -1:
			d[nx][ny] = d[x][y] + 1
			q.append((nx, ny))
print(d[gy][gx])