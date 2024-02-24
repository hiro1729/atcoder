S = input()
cnt = [0] * 26
for i in S:
	cnt[ord(i) - ord('a')] += 1
d = cnt.index(1)
print(S.index(chr(ord('a') + d)) + 1)