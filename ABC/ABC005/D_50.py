n = int(input())
d = [list(map(int, input().split())) for _ in range(n)]
for _ in range(int(input())):
    p = int(input())
    ans = 0
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i * j > p:
                break
            for s in range(n - i + 1):
                for t in range(n - j + 1):
                    now = 0
                    for k in range(i):
                        for l in range(j):
                            now += d[s + k][t + l]
                    ans = max(ans, now)
    print(ans)