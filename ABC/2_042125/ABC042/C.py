N, K = map(int, input().split())
D = set(input().split())
while True:
	if len(set(str(N)) & D) == 0:
		exit(print(N))
	N += 1