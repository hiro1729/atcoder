import strutils, sequtils

let N = stdin.readLine.parseInt
var
  A = newSeq[int](N)
  B = newSeq[int](N)
  cnt = newSeq[int](2 * N)
for i in 0..<N:
  let a_b = stdin.readLine.split().map(parseInt)
  A[i] = a_b[0] - 1
  B[i] = a_b[1] - 1
  if A[i] > B[i]:
    swap(A[i], B[i])
  inc cnt[A[i]]
  dec cnt[B[i]]
for i in 1..<(2 * N):
  cnt[i] += cnt[i - 1]
for i in 0..<N:
  if cnt[A[i]] < cnt[B[i] - 1]:
    echo "Yes"
    quit()
echo "No"