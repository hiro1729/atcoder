import math
n = int(input())
a = [tuple(map(int, input().split())) for i in range(n)]
x = set()
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        dx = a[i][0] - a[j][0]
        dy = a[i][1] - a[j][1]
        g = math.gcd(dx, dy)
        x.add((dx // g, dy // g))
print(len(x))