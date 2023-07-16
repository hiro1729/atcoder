r, g, b = map(int, input().split())
if r <= 5 and g <= 5 and b <= 5:
    l = [0, 0, 1, 2, 4, 6]
    print(l[r] + l[g] + l[b])