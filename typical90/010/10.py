n = int(input())
c1 = [0] * (n + 1)
c2 = [0] * (n + 1)
for i in range(n):
    c, p = map(int, input().split())
    if c == 1:
        c1[i + 1] = p
    else:
        c2[i + 1] = p
for i in range(n):
    c1[i + 1] += c1[i]
    c2[i + 1] += c2[i]
q = int(input())
for _ in range(q):
    l, r = map(int, input().split())
    print(c1[r] - c1[l - 1], c2[r] - c2[l - 1])