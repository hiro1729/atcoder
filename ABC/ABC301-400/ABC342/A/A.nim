import strutils
let S = stdin.readLine
var cnt = newSeq[int](26)
for c in S:
  inc cnt[ord(c) - ord('a')]
let d = cnt.find(1)
echo S.find(chr(ord('a') + d)) + 1