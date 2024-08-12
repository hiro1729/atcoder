N, D = map(int, input().split())
x = [0] * N
y = [0] * N
for i in range(N):
	x[i], y[i] = map(int, input().split())
x.sort()
y.sort()

M = 2000001
ca = [0] * (D + 1)
j = 0
ns = sum(x) + N * M

for i in range(-M, M + 1):
	while j < N and x[j] <= i:
		j += 1
	ns += 2 * j - N
	if ns <= D:
		ca[ns] += 1

for i in range(D):
	ca[i + 1] += ca[i]

j = 0
ns = sum(y) + N * M
ans = 0

for i in range(-M, M + 1):
	while j < N and y[j] <= i:
		j += 1
	ns += 2 * j - N
	if ns <= D:
		ans += ca[D - ns]

print(ans)