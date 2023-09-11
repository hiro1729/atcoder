n = int(input())
a = int(input())
b = int(input())
c = int(input())
if n in [a, b, c]:
	exit(print("NO"))
for i in range(100):
	k = 0
	for j in range(1, 4):
		if n - j >= 0 and n - j not in [a, b, c]:
			k = j
	n -= k
	if n == 0:
		break
print("YES" if n == 0 else "NO")