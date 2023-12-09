N, K = map(int, input().split())
R = list(map(int, input().split()))
R.sort()
now = 0
for i in R[-K:]:
	now = (now + i) / 2
print(now)