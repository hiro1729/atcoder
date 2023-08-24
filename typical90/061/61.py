c = [-1] * 300030
l = 100010
r = 100010
for _ in range(int(input())):
	t, x = map(int, input().split())
	if t == 1:
		l -= 1
		c[l] = x
	elif t == 2:
		c[r] = x
		r += 1
	else:
		print(c[l + x - 1])