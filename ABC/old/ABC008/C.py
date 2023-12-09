N = int(input())
C = [int(input()) for _ in range(N)]
s = 0
for i in range(N):
	k = 0
	for j in range(N):
		if C[i] % C[j] == 0:
			k += 1
	s += (k + 1) / (2 * k) if k % 2 == 1 else 0.5
print(s)