import strutils, sequtils, deques

let N = stdin.readLine.parseInt
var S = newSeq[string](N)
for i in 0..<N:
  S[i] = stdin.readLine
var
  player1_x = -1
  player1_y = -1
  player2_x = -1
  player2_y = -1
for i in 0..<N:
  for j in 0..<N:
    if S[i][j] == 'P':
      if player1_x == -1 and player1_y == -1:
        player1_x = i
        player1_y = j
      else:
        player2_x = i
        player2_y = j
var d = newSeqWith(N, newSeqWith(N, newSeqWith(N, newSeqWith(N, -1))))
d[player1_x][player1_y][player2_x][player2_y] = 0
var q = [(player1_x, player1_y, player2_x, player2_y)].toDeque()
let dxy = [(-1, 0), (0, -1), (1, 0), (0, 1)]
while q.len > 0:
  let (now1_x, now1_y, now2_x, now2_y) = q.popFirst
  for (dx, dy) in dxy:
    var
      next1_x = now1_x + dx
      next1_y = now1_y + dy
      next2_x = now2_x + dx
      next2_y = now2_y + dy
    if not(0 <= next1_x and next1_x < N and 0 <= next1_y and next1_y < N) or S[next1_x][next1_y] == '#':
      next1_x = now1_x
      next1_y = now1_y
    if not(0 <= next2_x and next2_x < N and 0 <= next2_y and next2_y < N) or S[next2_x][next2_y] == '#':
      next2_x = now2_x
      next2_y = now2_y
    if d[next1_x][next1_y][next2_x][next2_y] >= 0:
      continue
    d[next1_x][next1_y][next2_x][next2_y] = d[now1_x][now1_y][now2_x][now2_y] + 1
    if next1_x == next2_x and next1_y == next2_y:
      echo d[next1_x][next1_y][next2_x][next2_y]
      quit()
    q.addLast((next1_x, next1_y, next2_x, next2_y))
echo -1