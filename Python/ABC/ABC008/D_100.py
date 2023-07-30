# C++で99点の解法でもPythonでは80点になるため99点解法は飛ばします
# メモ化
from functools import lru_cache
w, h = map(int, input().split())
n = int(input())
x = [0] * n
y = [0] * n
for i in range(n):
  x[i], y[i] = map(int, input().split())
  x[i] -= 1
  y[i] -= 1
@lru_cache(maxsize = None)
def f(l, r, d, u):
  if l >= r or d >= u:
    return 0
  a = 0
  for i in range(n):
    if l <= x[i] < r and d <= y[i] < u:
      a = max(a, f(l, x[i], d, y[i]) + f(l, x[i], y[i] + 1, u) + f(x[i] + 1, r, d, y[i]) + f(x[i] + 1, r, y[i] + 1, u) + r - l + u - d - 1)
  return a
print(f(0, w, 0, h))