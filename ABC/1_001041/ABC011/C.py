N = int(input())
NG = [int(input()) for _ in range(3)]
if N in NG:
	exit(print("NO"))
for i in range(100):
	k = 0
	for j in range(1, 4):
		if N >= j and N - j not in NG:
			k = j
	N -= k
	if N == 0:
		exit(print("YES"))
print("NO")