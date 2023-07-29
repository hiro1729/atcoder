w, h = map(int, input().split())
n = int(input())
t = [tuple(map(int, input().split())) for _ in range(n)]
ans = 0
for i in range(n):
    ans |= (1 << i)
def dfs(m, a, b, c, d):
    if m == 0:
        return 0
    v = []
    for i in range(n):
        if (m >> i) & 1:
            v.append(i)
    res = 0
    for i in v:
        p, q, r, s = 0, 0, 0, 0
        xi, yi = t[i]
        for j in v:
            xj, yj = t[j]
            if xj < xi and yj < yi:
                p |= (1 << j)
            if xj < xi and yj > yi:
                q |= (1 << j)
            if xj > xi and yj < yi:
                r |= (1 << j)
            if xj > xi and yj > yi:
                s |= (1 << j)
        cr = c - a + d - b + 1 + dfs(p, a, b, xi - 1, yi - 1) + dfs(q, a, yi + 1, xi - 1, d) + dfs(r, xi + 1, b, c, yi - 1) + dfs(s, xi + 1, yi + 1, c, d)
        res = max(res, cr)
    return res
print(dfs(ans, 1, 1, w, h))