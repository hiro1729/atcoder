h, w = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(h)]
r = [0] * h
c = [0] * w
for i in range(h):
    for j in range(w):
        r[i] += a[i][j]
        c[j] += a[i][j]
for i in range(h):
    print(*[r[i] + c[j] - a[i][j] for j in range(w)])