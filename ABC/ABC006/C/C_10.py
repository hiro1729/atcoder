n, m = map(int, input().split())
if n <= 100 and m <= 500:
    for i in range(n + 1):
        for j in range(n + 1):
            for k in range(n + 1):
                if i + j + k == n and 2 * i + 3 * j + 4 * k == m:
                    exit(print(i, j, k))
print(-1, -1, -1)