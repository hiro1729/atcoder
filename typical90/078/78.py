n, m = map(int, input().split())
c = [0] * n
for _ in range(m):
	a, b = map(int, input().split())
	c[max(a, b) - 1] += 1
print(c.count(1))