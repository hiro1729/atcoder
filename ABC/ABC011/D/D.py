from collections import defaultdict
n, d = map(int, input().split())
x, y = map(int, input().split())
if x % d or y % d:
	exit(print(0))
x //= d
y //= d
if (x + y) % 2 != n % 2 or abs(x + y) > n or abs(x - y) > n:
	exit(print(0))
a = (x + y + n) // 2
b = (x - y + n) // 2
c = [[] for _ in range(n + 1)]
for i in range(n + 1):
	if i == 0:
		c[i] = [1.0]
		continue
	c[i] = [0.0 for _ in range(i + 1)]
	for j in range(i + 1):
		if j:
			c[i][j] += c[i - 1][j - 1]
		if j < i:
			c[i][j] += c[i - 1][j]
		c[i][j] /= 2
print(c[n][a] * c[n][b])