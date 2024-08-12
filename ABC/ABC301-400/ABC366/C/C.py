from collections import defaultdict

Q = int(input())
B = defaultdict(int)
for _ in range(Q):
	query = list(map(int, input().split()))
	if query[0] == 1:
		x = query[1]
		B[x] += 1
	elif query[0] == 2:
		x = query[1]
		B[x] -= 1
		if B[x] == 0:
			del B[x]
	else:
		print(len(B))