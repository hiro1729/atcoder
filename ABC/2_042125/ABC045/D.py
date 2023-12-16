from collections import defaultdict
H, W, N = map(int, input().split())
ans = [0] * 10
dd = defaultdict(int)
for _ in range(N):
	a, b = map(int, input().split())
	for d in [-1, 0, 1]:
		for e in [-1, 0, 1]:
			if 1 < a + d < H and 1 < b + e < W:
				ans[dd[(a + d, b + e)]] -= 1
				dd[(a + d, b + e)] += 1
				ans[dd[(a + d, b + e)]] += 1
ans[0] = (H - 2) * (W - 2) - sum(ans[1:])
print(*ans)