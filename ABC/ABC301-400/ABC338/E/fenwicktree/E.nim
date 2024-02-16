import strutils, sequtils

type BIT = object
  n: int
  a: seq[int]

proc initBIT(n: int): BIT =
  return BIT(n: n, a: newSeq[int](n))

proc add(bit: var BIT, p: int, x: int) =
  var t = p + 1
  while t <= bit.n:
    bit.a[t - 1] += x
    t += t and -t

proc sum0(bit: var BIT, r: int): int =
  var
    s = 0
    x = r
  while x > 0:
    s += bit.a[x - 1]
    x -= x and -x
  return s

proc sum(bit: var BIT, l, r: int): int =
  return bit.sum0(r) - bit.sum0(l)

let N = stdin.readLine.parseInt
var
  A = newSeq[int](N)
  B = newSeq[int](N)
  fwA = initBIT(2 * N)
  fwB = initBIT(2 * N)
for i in 0..<N:
  let a_b = stdin.readLine.split().map(parseInt)
  A[i] = a_b[0] - 1
  B[i] = a_b[1] - 1
  if A[i] > B[i]:
    swap(A[i], B[i])
  fwA.add(A[i], 1)
  fwB.add(B[i], 1)
for i in 0..<N:
  if fwB.sum(A[i] + 1, B[i]) < fwA.sum(A[i] + 1, B[i]):
    echo "Yes"
    quit()
echo "No"