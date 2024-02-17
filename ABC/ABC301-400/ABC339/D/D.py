from collections import deque
N = int(input())
S = [input() for _ in range(N)]
player1_x, player1_y = -1, -1
player2_x, player2_y = -1, -1
for i in range(N):
	for j in range(N):
		if S[i][j] == 'P':
			if player1_x == player1_y == -1:
				player1_x = i
				player1_y = j
			else:
				player2_x = i
				player2_y = j
d = [[[[-1] * N for _ in range(N)] for _ in range(N)] for _ in range(N)]
d[player1_x][player1_y][player2_x][player2_y] = 0
q = deque([(player1_x, player1_y, player2_x, player2_y)])
dxy = [(-1, 0), (0, -1), (1, 0), (0, 1)]
while q:
	now1_x, now1_y, now2_x, now2_y = q.popleft()
	for dx, dy in dxy:
		next1_x, next1_y = now1_x + dx, now1_y + dy
		next2_x, next2_y = now2_x + dx, now2_y + dy
		if not(0 <= next1_x < N and 0 <= next1_y < N) or S[next1_x][next1_y] == '#':
			next1_x, next1_y = now1_x, now1_y
		if not(0 <= next2_x < N and 0 <= next2_y < N) or S[next2_x][next2_y] == '#':
			next2_x, next2_y = now2_x, now2_y
		if d[next1_x][next1_y][next2_x][next2_y] >= 0:
			continue
		d[next1_x][next1_y][next2_x][next2_y] = d[now1_x][now1_y][now2_x][now2_y] + 1
		if next1_x == next2_x and next1_y == next2_y:
			print(d[next1_x][next1_y][next2_x][next2_y])
			exit()
		q.append((next1_x, next1_y, next2_x, next2_y))
print(-1)