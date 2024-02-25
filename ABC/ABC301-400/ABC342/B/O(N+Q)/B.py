N = int(input())
P = list(map(int, input().split()))
Prev = [0] * N
for i in range(N):
	Prev[P[i] - 1] = i
Q = int(input())
for _ in range(Q):
	A, B = map(int, input().split())
	print(A if Prev[A - 1] < Prev[B - 1] else B)