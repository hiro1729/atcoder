from collections import defaultdict
N = int(input())
S = [input() for _ in range(N)]
d = defaultdict(int)
for s in S:
	d[s] += 1
m = max(d.values())
for i, j in d.items():
	if m == j:
		exit(print(i))