N, M = map(int, input().split())
a = 2 * N - M // 2 - M % 2
c = M // 2 - N
if a >= 0 and c >= 0:
	print(a, M % 2, c)
else:
	print(-1, -1, -1)