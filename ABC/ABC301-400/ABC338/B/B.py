S = input()
cnt = [0] * 26
for i in S:
	cnt[ord(i) - ord('a')] += 1
mx = max(cnt)
for i in range(26):
	if cnt[i] == mx:
		print(chr(ord('a') + i))
		exit()