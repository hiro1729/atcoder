import strutils, sequtils
let N = stdin.readLine.parseInt
let P = stdin.readLine.split().map(parseInt)
var Prev = newSeq[int](N)
for i in 0..<N:
  Prev[P[i] - 1] = i
let Q = stdin.readLine.parseInt
for i in 0..<Q:
  let a_b = stdin.readLine.split().map(parseInt)
  let
    A = a_b[0]
    B = a_b[1]
  echo if Prev[A - 1] < Prev[B - 1]: A else: B