N = int(input())
Q = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))
ans = 0
for i in range(1000001):
	C = [Q[j] - A[j] * i for j in range(N)]
	if min(C) >= 0:
		ans = max(ans, i + min(C[j] // B[j] for j in range(N) if B[j] != 0))
print(ans)