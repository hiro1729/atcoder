S = input()
t = 2 ** (len(S) - 1)
now = t
ans = 0
for i in S[::-1]:
	ans += now * int(i)
	now = now * 5 + t // 2
print(ans)