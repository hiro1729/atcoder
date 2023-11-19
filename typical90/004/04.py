H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]

B = [0] * H
C = [0] * W
for i in range(H):
	for j in range(W):
		B[i] += A[i][j]
		C[j] += A[i][j]

ans = [[0] * W for _ in range(H)]
for i in range(H):
	for j in range(W):
		ans[i][j] = B[i] + C[j] - A[i][j]

for i in ans:
	print(*i)