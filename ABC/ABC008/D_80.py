from itertools import permutations
h, w = map(int, input().split())
n = int(input())
m = [tuple(map(int, input().split())) for _ in range(n)]
ans = 0
for p in permutations(list(range(n))):
    a = [[True] * (w + 2) for _ in range(h + 2)]
    for i in range(w + 2):
        a[0][i] = False
        a[h + 1][i] = False
    for i in range(h + 2):
        a[i][0] = False
        a[i][w + 1] = False
    c = 0
    for i in range(n):
        x, y = m[p[i]]
        a[x][y] = False
        c += 1
        for dx, dy in zip([0, 1, 0, -1], [1, 0, -1, 0]):
            nx = x + dx
            ny = y + dy
            while a[nx][ny]:
                a[nx][ny] = False
                nx += dx
                ny += dy
                c += 1
    ans = max(ans, c)
print(ans)