k, m = map(int, input().split())
a = list(map(int, input().split()))
c = [list(map(int, input().split()))] + [[0] * k for _ in range(k + 1)]
for i in range(k - 1):
    c[i + 1][i] = -1
x = [[0] * k for _ in range(k)]
for i in range(k):
    x[i][i] = -1
def mul(a, b):
    t = [[0] * k for _ in range(k)]
    for i in range(k):
        for j in range(k):
            for s in range(k):
                t[i][j] ^= a[i][s] & b[s][j]
    return t
m -= 1
while m:
    if m % 2:
        x = mul(x, c)
    c = mul(c, c)
    m //= 2
ans = 0
for i in range(k):
    ans ^= x[k - 1][i] & a[k - i - 1]
print(ans)