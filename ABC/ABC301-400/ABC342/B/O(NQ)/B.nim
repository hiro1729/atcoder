import strutils, sequtils
let N = stdin.readLine.parseInt
let P = stdin.readLine.split().map(parseInt)
let Q = stdin.readLine.parseInt
for i in 0..<Q:
  let a_b = stdin.readLine.split().map(parseInt)
  let
    A = a_b[0]
    B = a_b[1]
  echo if P.find(A) < P.find(B): A else: B