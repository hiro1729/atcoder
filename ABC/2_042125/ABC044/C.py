N, A = map(int, input().split())
x = list(map(int, input().split()))
m = max(x)
dp = [[0] * (2 * N * m + 1) for _ in range(N + 1)]
dp[0][N * m] = 1
for i in range(N):
	for j in range(2 * N * m + 1):
		dp[i + 1][j] = dp[i][j]
		if 0 <= j - (x[i] - A) <= 2 * N * m:
			dp[i + 1][j] += dp[i][j - (x[i] - A)]
print(dp[N][N * m] - 1)