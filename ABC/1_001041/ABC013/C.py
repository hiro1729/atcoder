N, H = map(int, input().split())
A, B, C, D, E = map(int, input().split())
ans = 10 ** 18
for i in range(N + 1):
	j = max(0, ((N - i) * E - B * i - H) // (D + E) + 1)
	ans = min(ans, A * i + C * j)
print(ans)