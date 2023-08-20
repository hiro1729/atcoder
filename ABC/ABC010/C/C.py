def d(x, y, tx, ty):
  return ((x - tx) ** 2 + (y - ty) ** 2) ** 0.5
txa, tya, txb, tyb, t, v = map(int, input().split())
for _ in range(int(input())):
    x, y = map(int, input().split())
    if d(x, y, txa, tya) + d(x, y, txb, tyb) <= t * v:
        exit(print("YES"))
print("NO")