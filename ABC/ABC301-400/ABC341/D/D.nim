import strutils, sequtils, math
let n_m_k = stdin.readLine.split().map(parseInt)
let
  N = n_m_k[0]
  M = n_m_k[1]
  K = n_m_k[2]
  L = lcm(N, M)
var
  left = 0
  right = 1 shl 60
while left + 1 < right:
  let mid = (left + right) div 2
  if mid div N + mid div M - mid div L * 2 < K:
    left = mid
  else:
    right = mid
echo right