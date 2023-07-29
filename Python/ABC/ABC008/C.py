from itertools import permutations
n = int(input())
c = [int(input()) for _ in range(n)]
s = 0
cn = 0
for p in list(permutations(list(range(n)))):
    cn += 1
    b = [True] * n
    for i in range(n):
        for j in range(i + 1, n):
            if c[p[j]] % c[p[i]] == 0:
                b[j] = not b[j]
    for i in range(n):
        if b[i]:
            s += 1
print(s / cn)