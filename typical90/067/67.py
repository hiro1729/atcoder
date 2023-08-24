n, k = input().split()
k = int(k)
for _ in range(k):
    n10 = 0
    for i in n:
        n10 = n10 * 8 + int(i)
    n = ""
    while n10:
        n += str(n10 % 9)
        n10 //= 9
    n = n[::-1].replace('8', '5')
print(n)