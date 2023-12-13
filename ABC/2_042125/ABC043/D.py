s = input()
n = len(s)
for i in range(n - 1):
	if s[i] == s[i + 1]:
		exit(print(i + 1, i + 2))
for i in range(n - 2):
	if s[i] == s[i + 2]:
		exit(print(i + 1, i + 3))
print(-1, -1)