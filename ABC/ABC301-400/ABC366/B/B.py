N = int(input())
S = [input() for _ in range(N)]
L = max(map(len, S))
for i in range(L):
	ans = ""
	for j in S[::-1]:
		ans += j[i] if i < len(j) else '*'
	print(ans.rstrip('*'))