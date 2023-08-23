from math import gcd
a, b, c = map(int, input().split())
g = gcd(gcd(a, b), c)
print(a // g + b // g + c // g - 3)