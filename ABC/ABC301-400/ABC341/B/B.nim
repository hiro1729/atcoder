import strutils, sequtils
let N = stdin.readLine.parseInt
var A = stdin.readLine.split().map(parseInt)
for i in 0..<(N - 1):
  let s_t = stdin.readLine.split().map(parseInt)
  let
    S = s_t[0]
    T = s_t[1]
  A[i + 1] += A[i] div S * T
  A[i] = A[i] div S
echo A[N - 1]