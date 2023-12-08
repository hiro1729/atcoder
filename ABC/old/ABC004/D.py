def f(a, b):
	b += a
	if a > -1:
		return (b - a) * (a + b - 1) // 2
	if b < 2:
		return (a - b) * (a + b - 1) // 2
	return a * (a - 1) // 2 + b * (b - 1) // 2
R, G, B = map(int, input().split())
ans = 10 ** 6
for i in range(-300, 301):
	ans = min(ans, f(min(i - R, -100 - R // 2) + 100, R) + f(i, G) + f(max(i + G, 100 - B // 2) - 100, B))
print(ans)