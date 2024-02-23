import strutils, sequtils
let h_w_n = stdin.readLine.split().map(parseInt)
let
  H = h_w_n[0]
  W = h_w_n[1]
  N = h_w_n[2]
var
  A = newSeqWith(H, '.'.repeat(W))
  nowx = 0
  nowy = 0
  dx = -1
  dy = 0
for i in 0..<N:
  if A[nowx][nowy] == '.':
    (dx, dy) = (dy, -dx)
    A[nowx][nowy] = '#'
  else:
    (dx, dy) = (-dy, dx)
    A[nowx][nowy] = '.'
  nowx += dx
  nowy += dy
  nowx = (nowx + H) mod H
  nowy = (nowy + W) mod W
for i in A:
  echo i