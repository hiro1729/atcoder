S = input()
T = input()
for i, j in zip(S, T):
	if i == j:
		continue
	if i == '@' and j in "atcoder":
		continue
	if i in "atcoder" and j == '@':
		continue
	exit(print("You will lose"))
print("You can win")