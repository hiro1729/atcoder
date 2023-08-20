n = int(input())
s = [int(input()) for _ in range(n)]
s = list(set(s))
s.sort(reverse = True)
print(s[1])