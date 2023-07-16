c = [input().split() for _ in range(4)]
for i in range(4):
    print(*[c[3 - i][3 - j] for j in range(4)])