N, M = map(int, input().split())
X = list(map(int, input().split()))
for i in range(M):
	X[i] -= 1
s = 0
ac = [0] * (N + 1)
for i in range(M - 1):
	k = abs(X[i + 1] - X[i])
	s += min(k, N - k)
	if k <= N // 2:
		ac[min(X[i], X[i + 1])] += N - k * 2
		ac[max(X[i], X[i + 1])] -= N - k * 2
	else:
		ac[0] += 2 * k - N
		ac[min(X[i], X[i + 1])] -= 2 * k - N
		ac[max(X[i], X[i + 1])] += 2 * k - N
		ac[N] -= 2 * k - N
for i in range(N):
	ac[i + 1] += ac[i]
print(s + min(ac[:-1]))