import strutils, sequtils
let n_m = stdin.readLine.split().map(parseInt)
let
  N = n_m[0]
  M = n_m[1]
var X = stdin.readLine.split().map(parseInt)
for i in 0..<M:
  X[i] -= 1
var s = 0
var ac = newSeq[int](N + 1)
for i in 0..<(M-1):
  let k = abs(X[i + 1] - X[i])
  s += min(k, N - k)
  if k <= N div 2:
    ac[min(X[i], X[i + 1])] += N - k * 2
    ac[max(X[i], X[i + 1])] -= N - k * 2
  else:
    ac[0] += 2 * k - N
    ac[min(X[i], X[i + 1])] -= 2 * k - N
    ac[max(X[i], X[i + 1])] += 2 * k - N
    ac[N] -= 2 * k - N
for i in 0..<N:
  ac[i + 1] += ac[i]
echo s + min(ac[0..<N])