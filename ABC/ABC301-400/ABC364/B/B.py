H, W = map(int, input().split())
Si, Sj = map(int, input().split())
Si -= 1
Sj -= 1
C = [input() for _ in range(H)]
X = input()
for d in X:
	if d == 'U':
		if Si > 0 and C[Si - 1][Sj] == '.':
			Si -= 1
	if d == 'D':
		if Si < H - 1 and C[Si + 1][Sj] == '.':
			Si += 1
	if d == 'L':
		if Sj > 0 and C[Si][Sj - 1] == '.':
			Sj -= 1
	if d == 'R':
		if Sj < W - 1 and C[Si][Sj + 1] == '.':
			Sj += 1
print(Si + 1, Sj + 1)