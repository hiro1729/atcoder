N = int(input())
S = input()

r, s, p = 0, 0, 0
for c in S:
	r, s, p = max(s, p), max(p, r), max(r, s)
	if c == 'R':
		s = 0
		p += 1
	if c == 'S':
		p = 0
		r += 1
	if c == 'P':
		r = 0
		s += 1
print(max(r, s, p))