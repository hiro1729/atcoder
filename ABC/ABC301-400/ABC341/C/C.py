H, W, N = map(int, input().split())
T = input()
S = [input() for _ in range(H)]
ans = 0
for i in range(H):
	for j in range(W):
		if S[i][j] == '#':
			continue
		nowx, nowy = i, j
		ok = True
		for c in T:
			if c == 'U':
				nowx -= 1
			if c == 'D':
				nowx += 1
			if c == 'L':
				nowy -= 1
			if c == 'R':
				nowy += 1
			if S[nowx][nowy] == '#':
				ok = False
				break
		if ok:
			ans += 1
print(ans)