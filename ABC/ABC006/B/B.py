n = int(input())
a = [0] * 1000000
a[2] = 1
for i in range(3, 1000000):
    a[i] = (a[i - 3] + a[i - 2] + a[i - 1]) % 10007
print(a[n - 1])