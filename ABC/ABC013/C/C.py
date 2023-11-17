N, H = map(int, input().split())
A, B, C, D, E = map(int, input().split())
ans = 10 ** 12

# 普通の食事がi回
for i in range(N + 1):
	# 質素な食事をする必要がある最低の回数をx回とする
	x = max(0, (E * N - (B + E) * i - H) // (D + E) + 1)
	if i + x <= N:
		ans = min(ans, i * A + x * C)

print(ans)