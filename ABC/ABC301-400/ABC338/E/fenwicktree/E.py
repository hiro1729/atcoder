from atcoder.fenwicktree import FenwickTree

N = int(input())
A = [0] * N
B = [0] * N
fwA = FenwickTree(2 * N)
fwB = FenwickTree(2 * N)
for i in range(N):
	A[i], B[i] = map(int, input().split())
	A[i] -= 1
	B[i] -= 1
	if A[i] > B[i]:
		A[i], B[i] = B[i], A[i]
	fwA.add(A[i], 1)
	fwB.add(B[i], 1)
for i in range(N):
	if fwB.sum(A[i] + 1, B[i]) < fwA.sum(A[i] + 1, B[i]):
		print("Yes")
		exit()
print("No")