inf = 10 ** 9

N, K = map(int, input().split())
pairs = [tuple(map(int, input().split())) for _ in range(N)]
order = [((pairs[i][0] - 1) / pairs[i][1], i) for i in range(N)]
order.sort()
dp = [-inf] * (K + 1)
dp[0] = 1
for _, i in order:
	ndp = dp[:]
	for j in range(K):
		if dp[j] != -inf:
			ndp[j + 1] = max(ndp[j + 1], pairs[i][0] * dp[j] + pairs[i][1])
	dp = ndp
print(dp[K])