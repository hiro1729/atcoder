mod = 1000000007
n = 900
C = [[0] * (n + 1) for _ in range(n + 1)]
C[0][0] = 1
for i in range(1, n + 1):
    C[i][0] = 1
    C[i][i] = 1
    for j in range(1, i):
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod
def t(x, y):
    if x * y < d + l or x <= 0 or y <= 0:
        return 0
    return C[x * y][l + d] * C[l + d][l] % mod
r, c, x, y, d, l = map(int, open(0).read().split())
ans = (t(x, y) - t(x - 1, y) * 2 - t(x, y - 1) * 2 + t(x - 2, y) + t(x, y - 2) + t(x - 1, y - 1) * 4 - t(x - 2, y - 1) * 2 - t(x - 1, y - 2) * 2 + t(x - 2, y - 2)) % mod
print(ans * (r - x + 1) * (c - y + 1) % mod)