n = int(input())
c = [int(input()) for _ in range(n)]
s = 0
for i in range(n):
    k = 0
    for j in range(n):
        if c[i] % c[j] == 0:
            k += 1
    s += (k + 1) / (2 * k) if k % 2 == 1 else 0.5
print(s)