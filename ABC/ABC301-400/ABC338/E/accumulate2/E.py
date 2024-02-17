N = int(input())
A = [0] * N
B = [0] * N
cnt = [0] * (2 * N)
for i in range(N):
	A[i], B[i] = map(int, input().split())
	A[i] -= 1
	B[i] -= 1
	if A[i] > B[i]:
		A[i], B[i] = B[i], A[i]
	cnt[A[i]] += 1
	cnt[B[i]] -= 1
for i in range(1, 2 * N):
	cnt[i] += cnt[i - 1]
for i in range(N):
	if cnt[A[i]] < cnt[B[i] - 1]:
		print("Yes")
		exit()
print("No")