n = int(input())
c = [0] * 1000001
for _ in range(n):
	a, b = map(int, input().split())
	c[a] += 1
	if b < 1000000:
		c[b + 1] -= 1
for i in range(1000000):
	c[i + 1] += c[i]
print(max(c))