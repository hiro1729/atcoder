n, m = map(int, input().split())
a = 2 * n - m // 2 - m % 2
c = m // 2 - n
if a >= 0 and c >= 0:
    print(a, m % 2, c)
else:
    print(-1, -1, -1)