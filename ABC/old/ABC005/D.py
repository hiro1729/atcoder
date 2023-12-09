N = int(input())
D = [list(map(int, input().split())) for _ in range(N)]
A = [[0] * (N + 1) for _ in range(N + 1)]
for i in range(N):
	for j in range(N):
		A[i + 1][j + 1] = D[i][j]
for i in range(N):
	for j in range(N):
		A[i + 1][j + 1] += A[i][j + 1]
for i in range(N):
	for j in range(N):
		A[i + 1][j + 1] += A[i + 1][j]
t = [0] * (N * N + 1)
for i in range(N):
	for j in range(N):
		for k in range(i + 1, N + 1):
			for l in range(j + 1, N + 1):
				t[(k - i) * (l - j)] = max(t[(k - i) * (l - j)], A[k][l] - A[k][j] - A[i][l] + A[i][j])
for i in range(N * N):
	t[i + 1] = max(t[i + 1], t[i])
for _ in range(int(input())):
	print(t[int(input())])