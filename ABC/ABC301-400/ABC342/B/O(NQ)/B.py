N = int(input())
P = list(map(int, input().split()))
Q = int(input())
for _ in range(Q):
	A, B = map(int, input().split())
	print(A if P.index(A) < P.index(B) else B)