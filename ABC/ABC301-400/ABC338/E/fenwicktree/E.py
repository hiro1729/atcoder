from atcoder.fenwicktree import FenwickTree

N = int(input())
P = [[0, 0] for _ in range(N)]
fwA = FenwickTree(2 * N)
fwB = FenwickTree(2 * N)
for i in range(N):
	P[i] = list(map(int, input().split()))
	P[i][0] -= 1
	P[i][1] -= 1
	if P[i][0] > P[i][1]:
		P[i][0], P[i][1] = P[i][1], P[i][0]
	fwA.add(P[i][0], 1)
	fwB.add(P[i][1], 1)
P.sort()
for A, B in P:
	if fwB.sum(A + 1, B) < fwA.sum(A + 1, B):
		print("Yes")
		exit()
	fwA.add(A, -1)
	fwB.add(B, -1)
print("No")