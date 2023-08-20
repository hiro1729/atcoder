n = int(input())
a = [1, 2, 3, 4, 5, 6]
for i in range(n % 30):
    a[i % 5], a[i % 5 + 1] = a[i % 5 + 1], a[i % 5]
print(*a, sep = "")