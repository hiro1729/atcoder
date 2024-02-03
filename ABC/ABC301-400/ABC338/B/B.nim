import strutils, sequtils
let S = stdin.readLine
var cnt = newSeq[int](26)
for c in S:
  cnt[ord(c) - ord('a')] += 1
let mx = max(cnt)
for i in 0..25:
  if cnt[i] == mx:
    echo chr(ord('a') + i)
    quit()