N = int(input())
c = [1, 2, 3, 4, 5, 6]
for i in range(N % 30):
	c[i % 5], c[i % 5 + 1] = c[i % 5 + 1], c[i % 5]
print(*c, sep="")