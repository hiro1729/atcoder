N, M = map(int, input().split())
A = list(map(int, input().split()))
for _ in range(M * 2 - N):
	A.append(0)
A.sort()
ans = 0
for i in range(M):
	ans += (A[i] + A[2 * M - 1 - i]) ** 2
print(ans)