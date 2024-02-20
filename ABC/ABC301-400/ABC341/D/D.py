from math import lcm
N, M, K = map(int, input().split())
L = lcm(N, M)
left, right = 0, 1 << 60
while left + 1 < right:
	mid = (left + right) // 2
	if mid // N + mid // M - mid // L * 2 < K:
		left = mid
	else:
		right = mid
print(right)