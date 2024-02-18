import strutils, sequtils
let h_w_n = stdin.readLine.split().map(parseInt)
let
  H = h_w_n[0]
  W = h_w_n[1]
  N = h_w_n[2]
  T = stdin.readLine
var S = newSeq[string](H)
for i in 0..<H:
  S[i] = stdin.readLine
var ans = 0
for i in 0..<H:
  for j in 0..<W:
    if S[i][j] == '#':
      continue
    var
      nowx = i
      nowy = j
      ok = true
    for c in T:
      if c == 'U':
        dec nowx
      if c == 'D':
        inc nowx
      if c == 'L':
        dec nowy
      if c == 'R':
        inc nowy
      if S[nowx][nowy] == '#':
        ok = false
        break
    if ok:
      inc ans
echo ans