N, Q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
for _ in range(Q):
	b, k = map(int, input().split())
	le, ri = -1, N - k + 1
	while le + 1 < ri:
		mi = (le + ri) // 2
		if b - a[mi] >= a[mi + k - 1] - b:
			le = mi
		else:
			ri = mi
	ans = 10 ** 9
	if le >= 0:
		ans = min(ans, b - a[le])
	if ri <= N - k:
		ans = min(ans, a[ri + k - 1] - b)
	print(ans)