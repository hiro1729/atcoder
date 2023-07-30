n, k = map(int, input().split())
s = input()
t = list(s)
for i in range(n):
    x = i
    for j in range(i + 1, n):
        if t[x] > t[j]:
            u = t[:]
            u[i], u[j] = u[j], u[i]
            c = 0
            for l in range(n):
                if s[l] != u[l]:
                    c += 1
            if c <= k:
                x = j
    t[i], t[x] = t[x], t[i]
print(''.join(t))