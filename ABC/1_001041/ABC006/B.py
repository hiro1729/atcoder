n = int(input())
a = [0, 0, 0, 1]
for _ in range(n):
	a.append((a[-1] + a[-2] + a[-3]) % 10007)
print(a[n])