mod = 1000000007
n = 900
C = [[0] * (n + 1) for _ in range(n + 1)]
C[0][0] = 1
for i in range(1, n + 1):
    C[i][0] = 1
    C[i][i] = 1
    for j in range(1, i):
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod
r, c, x, y, d, l = map(int, open(0).read().split())
if d + l == x * y:
    print(C[D + l][d] * (r - x + 1) * (c - y + 1) % mod)