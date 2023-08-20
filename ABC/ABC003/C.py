n, k = map(int, input().split())
r = list(map(int, input().split()))
r.sort()
ans = 0.0
for i in range(n - k, n):
    ans = (ans + r[i]) / 2
print(ans)