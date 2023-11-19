from bisect import *
n = int(input())
a = list(map(int, input().split()))
a.sort()
for _ in range(int(input())):
	b = int(input())
	le = bisect_left(a, b)
	ans = 1 << 60
	if le > 0:
		ans = min(ans, abs(a[le - 1] - b))
	if le < n:
		ans = min(ans, abs(a[le] - b))
	print(ans)