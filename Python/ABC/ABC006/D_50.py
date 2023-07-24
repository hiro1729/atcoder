n = int(input())
m = 0
c = [int(input()) for _ in range(n)]
dp = [0] * n
for i in range(n):
    dp[i] = 1
    for j in range(n):
        if c[i] <= c[j]:
            continue
        dp[i] = max(dp[i], dp[j] + 1)
    m = max(m, dp[i])
print(n - m)