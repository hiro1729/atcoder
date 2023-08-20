n = int(input())
a = [int(input()) for _ in range(n)]
ans = n
for i in range(1 << n):
    c = 0
    b = []
    for j in range(n):
        if i & (1 << j):
            b.append(a[j])
            c += 1
    ok = True
    for i in range(c - 1):
        if b[i] > b[i + 1]:
            ok = False
    if ok:
        ans = min(ans, n - c)
print(ans)