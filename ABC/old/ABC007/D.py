def dfs(s):
	if len(s) == 1:
		if s in "0123":
			return int(s) + 1
		if s in "45678":
			return int(s)
		return 8
	x = int(s[0])
	if x <= 3:
		return dfs(s[1:]) + x * 8 ** (len(s) - 1)
	if x == 4:
		return 4 * 8 ** (len(s) - 1)
	if x <= 8:
		return dfs(s[1:]) + (x - 1) * 8 ** (len(s) - 1)
	return 8 ** len(s)
a, b = map(int, input().split())
print(b - a + 1 - (dfs(str(b)) - dfs(str(a - 1))))