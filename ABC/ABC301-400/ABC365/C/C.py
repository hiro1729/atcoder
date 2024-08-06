N, M = map(int, input().split())
A = list(map(int, input().split()))
le = 0
ri = max(A) + 1
while le + 1 < ri:
	mi = (le + ri) // 2
	if sum(min(i, mi) for i in A) <= M:
		le = mi
	else:
		ri = mi
print(le if le < max(A) else "infinite")