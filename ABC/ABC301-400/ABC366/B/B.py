N = int(input())
S = [input() for _ in range(N)]
L = max(len(S[i]) for i in range(N))
for i in range(L):
	ans = ""
	for j in range(N - 1, -1, -1):
		if i < len(S[j]):
			ans += S[j][i]
		else:
			ans += '*'
	print(ans.rstrip('*'))