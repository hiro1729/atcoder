xa, xb, ya, yb, za, zb = map(int, input().split())
ya -= xa
za -= xa
yb -= xb
zb -= xb
print(abs(ya * zb - yb * za) / 2)