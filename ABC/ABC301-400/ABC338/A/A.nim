import strutils, sequtils
let S = stdin.readLine
echo:
  if S[0].isUpperAscii and S[1..<len(S)].allIt(it.isLowerAscii):
    "Yes"
  else:
    "No"