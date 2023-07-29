from collections import defaultdict
n = int(input())
d = defaultdict(int)
for _ in range(n):
  s = input()
  d[s] += 1
l = d.items()
print(sorted(l, key = lambda x: x[1])[-1][0])