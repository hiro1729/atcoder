n = int(input())
d = [list(map(int, input().split())) for _ in range(n)]
dac = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(n):
    for j in range(n):
        dac[i + 1][j + 1] = dac[i + 1][j] + d[i][j]
for i in range(n):
    for j in range(n):
        dac[i + 1][j] += dac[i][j]
for _ in range(int(input())):
    p = int(input())
    ans = 0
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i * j > p:
                break
            now = 0
            for s in range(n - i + 1):
                for t in range(n - j + 1):
                    now = max(now, dac[s][t] + dac[s + i][t + j] - dac[s][t + j] - dac[s + i][t])
            ans = max(ans, now)
    print(ans)