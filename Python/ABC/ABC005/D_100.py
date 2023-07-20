n = int(input())
d = [[0] * (n + 1)] + [[0] + list(map(int, input().split())) for _ in range(n)]
m = [0] * (n * n + 1)
for i in range(1, n + 1):
    for j in range(1, n + 1):
        d[i][j] += d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1]
        for k in range(i):
            for l in range(j):
                s = (i - k) * (j - l)
                m[s] = max(m[s], d[i][j] - d[i][l] - d[k][j] + d[k][l])
for _ in range(int(input())):
    print(max(m[:int(input()) + 1]))