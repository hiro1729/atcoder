from functools import lru_cache
W, H = map(int, input().split())
N = int(input())
X = [0] * N
Y = [0] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())
	X[i] -= 1
	Y[i] -= 1
@lru_cache(maxsize = None)
def f(l, r, d, u):
	if l >= r or d >= u:
		return 0
	a = 0
	for x, y in zip(X, Y):
		if l <= x < r and d <= y < u:
			a = max(a, f(l, x, d, y) + f(l, x, y + 1, u) + f(x + 1, r, d, y) + f(x + 1, r, y + 1, u) + r - l + u - d - 1)
	return a
print(f(0, W, 0, H))