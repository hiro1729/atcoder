a, b = map(int, input().split())
ans = 0
for i in range(a, b + 1):
    if '4' in str(i) or '9' in str(i):
        ans += 1
print(ans)