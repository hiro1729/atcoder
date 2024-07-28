from bisect import bisect_left

N, Q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
for _ in range(Q):
	b, k = map(int, input().split())
	le, ri = -1, 200000000
	while le + 1 < ri:
		mi = (le + ri) // 2
		if bisect_left(a, b + mi + 1) - bisect_left(a, b - mi) >= k:
			ri = mi
		else:
			le = mi
	print(ri)