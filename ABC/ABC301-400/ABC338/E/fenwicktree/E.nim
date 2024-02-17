import strutils, sequtils, algorithm

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
  P = newSeq[tuple[f: int, s: int]](N)
  fwA = initBIT(2 * N)
  fwB = initBIT(2 * N)
for i in 0..<N:
  let a_b = stdin.readLine.split().map(parseInt)
  P[i].f = a_b[0] - 1
  P[i].s = a_b[1] - 1
  if P[i].f > P[i].s:
    swap(P[i].f, P[i].s)
  fwA.add(P[i].f, 1)
  fwB.add(P[i].s, 1)
sort(P)
for (A, B) in P:
  if fwB.sum(A + 1, B) < fwA.sum(A + 1, B):
    echo "Yes"
    quit()
  fwA.add(A, -1)
  fwB.add(B, -1)
echo "No"