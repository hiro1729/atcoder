w = input()
c = [0] * 26
for i in w:
	c[ord(i) - ord('a')] += 1
print("Yes" if all(i % 2 == 0 for i in c) else "No")