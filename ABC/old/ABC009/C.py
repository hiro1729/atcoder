N, K = map(int, input().split())
s = input()
S = list(s)
for i in range(N):
	k = i
	for j in range(i + 1, N):
		if S[k] > S[j]:
			u = S[:]
			u[i], u[j] = u[j], u[i]
			if sum(s[l] != u[l] for l in range(N)) <= K:
				k = j
	S[i], S[k] = S[k], S[i]
print(''.join(S))