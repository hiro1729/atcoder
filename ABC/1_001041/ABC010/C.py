tx_a, ty_a, tx_b, ty_b, T, V = map(int, input().split())
for _ in range(int(input())):
	x, y = map(int, input().split())
	s = (tx_a - x) ** 2 + (ty_a - y) ** 2
	t = (tx_b - x) ** 2 + (ty_b - y) ** 2
	d = (T * V) ** 2 - s - t
	if 0 <= d and 4 * s * t <= d * d:
		exit(print("YES"))
print("NO")