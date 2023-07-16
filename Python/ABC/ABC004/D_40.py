def f(x):
    ans = ((x - 1) // 2) * ((x + 1) // 2)
    if x % 2 == 0:
        ans += x // 2
    return ans
r, g, b = map(int, input().split())
if r <= 40 and g <= 40 and b <= 40:
    print(f(r) + f(g) + f(b))