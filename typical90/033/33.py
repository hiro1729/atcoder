h, w = map(int, input().split())
if h == 1:
	print(w)
elif w == 1:
	print(h)
else:
	print(((h + 1) // 2) * ((w + 1) // 2))