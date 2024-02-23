H, W, N = map(int, input().split())
A = [['.'] * W for _ in range(H)]
nowx, nowy = 0, 0
dx, dy = -1, 0
for _ in range(N):
	if A[nowx][nowy] == '.':
		dx, dy = dy, -dx
		A[nowx][nowy] = '#'
	else:
		dx, dy = -dy, dx
		A[nowx][nowy] = '.'
	nowx += dx
	nowy += dy
	nowx %= H
	nowy %= W
for i in A:
	print(''.join(i))