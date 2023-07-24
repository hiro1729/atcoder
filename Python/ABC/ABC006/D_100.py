from bisect import bisect
n = int(input())
m = 1
c = [int(input()) for _ in range(n)]
l = [0] * n
l[0] = c[0]
for i in range(1, n):
    if l[m - 1] < c[i]:
        l[m] = c[i]
        m += 1
    else:
        l[bisect(l[:m], c[i])] = c[i]
print(n - m)