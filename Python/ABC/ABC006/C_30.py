n, m = map(int, input().split())
if n <= 1500 and n <= 7500:
    for i in range(n + 1):
        for j in range(n + 1):
            k = n - i - j
            if k >= 0 and 2 * i + 3 * j + 4 * k == m:
                exit(print(i, j, k))
print(-1, -1, -1)