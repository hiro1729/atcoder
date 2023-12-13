N = int(input())
a = list(map(int, input().split()))
ans = 10 ** 9
for i in range(-100, 101):
	ans = min(ans, sum((i - j) ** 2 for j in a))
print(ans)