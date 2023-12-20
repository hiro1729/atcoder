N = int(input())
t, a = map(int, input().split())
for _ in range(N - 1):
	T, A = map(int, input().split())
	x = (t + T - 1) // T
	y = (a + A - 1) // A
	b = max(x, y)
	t = T * b
	a = A * b
print(t + a)