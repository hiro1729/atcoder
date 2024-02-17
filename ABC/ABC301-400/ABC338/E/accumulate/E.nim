import strutils, sequtils

let N = stdin.readLine.parseInt
var
  A = newSeq[int](N)
  B = newSeq[int](N)
  cntA = newSeq[int](2 * N)
  cntB = newSeq[int](2 * N)
for i in 0..<N:
  let a_b = stdin.readLine.split().map(parseInt)
  A[i] = a_b[0] - 1
  B[i] = a_b[1] - 1
  if A[i] > B[i]:
    swap(A[i], B[i])
  inc cntA[A[i]]
  inc cntB[B[i]]
for i in 1..<(2 * N):
  cntA[i] += cntA[i - 1]
  cntB[i] += cntB[i - 1]
for i in 0..<N:
  if cntB[B[i] - 1] - cntB[A[i]] < cntA[B[i] - 1] - cntA[A[i]]:
    echo "Yes"
    quit()
echo "No"