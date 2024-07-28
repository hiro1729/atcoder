inf = 10 ** 9

N, X, Y = map(int, input().split())
dp = [[inf] * (X + 1) for _ in range(N + 1)]
dp[0][0] = 0
for i in range(N):
	A, B = map(int, input().split())
	for j in range(i, -1, -1):
		for k in range(X, A - 1, -1):
			if dp[j][k - A] < inf:
				dp[j + 1][k] = min(dp[j + 1][k], dp[j][k - A] + B)
for i in range(N, -1, -1):
	for j in range(X + 1):
		if dp[i][j] <= Y:
			print(min(i + 1, N))
			exit()