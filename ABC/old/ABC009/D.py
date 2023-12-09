K, M = map(int, input().split())
A = list(map(int, input().split()))
C = [list(map(int, input().split()))] + [[0] * K for _ in range(K - 1)]
for i in range(K - 1):
	C[i + 1][i] = -1
t = [[0] * K for _ in range(K)]
for i in range(K):
	t[i][i] = -1
def mul(a, b):
	r = [[0] * K for _ in range(K)]
	for i in range(K):
		for j in range(K):
			for k in range(K):
				r[i][j] ^= a[i][k] & b[k][j]
	return r
M -= 1
while M:
	if M % 2:
		t = mul(t, C)
	C = mul(C, C)
	M >>= 1
ans = 0
for i in range(K):
	ans ^= t[K - 1][i] & A[K - i - 1]
print(ans)