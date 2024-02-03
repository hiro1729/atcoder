import strutils, sequtils
let N = stdin.readLine.parseInt
let Q = stdin.readLine.split().map(parseInt)
let A = stdin.readLine.split().map(parseInt)
let B = stdin.readLine.split().map(parseInt)
var ans = 0
for i in 0..1000000:
  let C = (0..<N).mapIt(Q[it] - A[it] * i)
  if min(C) >= 0:
    ans = max(ans, i + min((0..<N).mapIt(if B[it] == 0: 1000000 else: C[it] div B[it])))
echo ans