from collections import deque
N = int(input())
P = [0] * (2 * N)
for i in range(N):
	A, B = map(int, input().split())
	A -= 1
	B -= 1
	if A > B:
		A, B = B, A
	P[A] = i
	P[B] = N + i
st = deque([])
for i in P:
	if i < N:
		st.append(i)
	else:
		if st.pop() != i - N:
			print("Yes")
			exit()
print("No")