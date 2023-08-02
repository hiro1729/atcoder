n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in a:
    ans += [0, 0, 1, 0, 1, 2, 3, 0, 1, 0][i]
print(ans)