N = int(input())
A = [0] * N
B = [0] * N
cntA = [0] * (2 * N)
cntB = [0] * (2 * N)
for i in range(N):
	A[i], B[i] = map(int, input().split())
	A[i] -= 1
	B[i] -= 1
	if A[i] > B[i]:
		A[i], B[i] = B[i], A[i]
	cntA[A[i]] += 1
	cntB[B[i]] += 1
for i in range(1, 2 * N):
	cntA[i] += cntA[i - 1]
	cntB[i] += cntB[i - 1]
for i in range(N):
	if cntB[B[i] - 1] - cntB[A[i]] < cntA[B[i] - 1] - cntA[A[i]]:
		print("Yes")
		exit()
print("No")