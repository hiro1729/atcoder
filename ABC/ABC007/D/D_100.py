def f(n):
    if n < 10:
        return sum(i not in (4, 9) for i in range(n + 1))
    q, r = divmod(n, 10)
    k = sum(x <= r for x in [0, 1, 2, 3, 5, 6, 7, 8])
    return k * f(q) + (8 - k) * f(q - 1)
a, b = map(int, input().split())
print(b - a + 1 - (f(b) - f(a - 1)))