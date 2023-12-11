N, M, D = map(int, input().split())
A = list(map(int, input().split()))
def f(S, T):
	return [T[i] for i in S]
dp = [[0] * N for _ in range(31)]
dp[0] = list(range(N))
for i in range(M)[::-1]:
	dp[0][A[i] - 1], dp[0][A[i]] = dp[0][A[i]], dp[0][A[i] - 1]
for i in range(30):
	dp[i + 1] = f(dp[i], dp[i])
ans = list(range(N))
for i in range(31):
	if D & (1 << i):
		ans = f(ans, dp[i])
for i in range(N):
	ans[i] += 1
print(*ans, sep='\n')