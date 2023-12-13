def f(b, n):
	c = 0
	while n:
		c += n % b
		n //= b
	return c
n = int(input())
s = int(input())
if n == s:
	exit(print(n + 1))
if n < s:
	exit(print(-1))
ans = 10 ** 18
for b in range(2, n + 1):
	if b * b > n:
		break
	if f(b, n) == s:
		ans = min(ans, b)
for p in range(1, n):
	if p * p >= n:
		break
	b = (n - s) // p + 1
	if b < 2:
		continue
	if f(b, n) == s:
		ans = min(ans, b)
print(-1 if ans == 10 ** 18 else ans)