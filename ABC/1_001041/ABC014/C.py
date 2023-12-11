n = int(input())
c = [0] * 1000002
for _ in range(n):
	a, b = map(int, input().split())
	c[a] += 1
	c[b + 1] -= 1
for i in range(1000001):
	c[i + 1] += c[i]
print(max(c))