N = int(input())
A = [[list(map(int, input().split())) for _ in range(N)] for _ in range(N)]
B = [[[0] * (N + 1) for _ in range(N + 1)] for _ in range(N + 1)]
for i in range(N):
	for j in range(N):
		for k in range(N):
			B[i + 1][j + 1][k + 1] = A[i][j][k]
for i in range(N + 1):
	for j in range(N + 1):
		for k in range(N):
			B[i][j][k + 1] += B[i][j][k]
for i in range(N + 1):
	for j in range(N):
		for k in range(N + 1):
			B[i][j + 1][k] += B[i][j][k]
for i in range(N):
	for j in range(N + 1):
		for k in range(N + 1):
			B[i + 1][j][k] += B[i][j][k]
for _ in range(int(input())):
	lx, rx, ly, ry, lz, rz = map(int, input().split())
	lx -= 1
	ly -= 1
	lz -= 1
	ans = 0
	ans += B[rx][ry][rz]
	ans -= B[rx][ry][lz]
	ans -= B[rx][ly][rz]
	ans += B[rx][ly][lz]
	ans -= B[lx][ry][rz]
	ans += B[lx][ry][lz]
	ans += B[lx][ly][rz]
	ans -= B[lx][ly][lz]
	print(ans)