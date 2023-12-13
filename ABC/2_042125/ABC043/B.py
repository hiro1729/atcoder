s = input()
ans = []
for c in s:
	if c == 'B':
		if ans:
			ans.pop()
	else:
		ans.append(c)
print(''.join(ans))