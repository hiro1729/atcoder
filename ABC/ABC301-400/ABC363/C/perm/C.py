from more_itertools import distinct_permutations

N, K = map(int, input().split())
S = sorted(list(input()))
ans = 0
for p in distinct_permutations(S):
	ok = True
	for i in range(N - K + 1):
		now_ok = True
		for j in range(K // 2):
			if p[i + j] != p[i + K - 1 - j]:
				now_ok = False
		if now_ok:
			ok = False
	if ok:
		ans += 1
print(ans)