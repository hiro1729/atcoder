N, D = map(int, input().split())
X, Y = map(int, input().split())
if X % D or Y % D:
	exit(print(0))
X //= D
Y //= D
if (X + Y) % 2 != N % 2 or abs(X + Y) > N or abs(X - Y) > N:
	exit(print(0))
a = (X + Y + N) // 2
b = (X - Y + N) // 2
C = [[] for _ in range(N + 1)]
for i in range(N + 1):
	if i == 0:
		C[i] = [1]
		continue
	C[i] = [0] * (i + 1)
	for j in range(i + 1):
		if j:
			C[i][j] += C[i - 1][j - 1]
		if j < i:
			C[i][j] += C[i - 1][j]
		C[i][j] /= 2
print(C[N][a] * C[N][b])