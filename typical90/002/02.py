def is_ok(par):
	dep = 0
	for i in par:
		if i == '(':
			dep += 1
		else:
			dep -= 1
		if dep < 0:
			return False
	return dep == 0
n = int(input())
if n % 2 == 1:
	exit(0)
ans = []
for i in range(1 << n):
	par = ""
	for j in range(n)[::-1]:
		par += "()"[(i >> j) & 1]
	if is_ok(par):
		print(par)