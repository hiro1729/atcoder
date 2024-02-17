import strutils, sequtils

let N = stdin.readLine.parseInt
var P = newSeq[int](2 * N)
for i in 0..<N:
  let a_b = stdin.readLine.split().map(parseInt)
  var
    A = a_b[0] - 1
    B = a_b[1] - 1
  if A > B:
    swap(A, B)
  P[A] = i
  P[B] = N + i
var st = newSeq[int]()
for i in P:
  if i < N:
    st.add(i)
  else:
    if st.pop() != i - N:
      echo "Yes"
      quit()
echo "No"