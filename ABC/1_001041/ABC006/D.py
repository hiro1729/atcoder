from bisect import bisect_left
def lis(a):
	r = [a[0]]
	for i in range(len(a)):
		if a[i] > r[-1]:
			r.append(a[i])
		else:
			r[bisect_left(r, a[i])] = a[i]
	return r
n = int(input())
c = [int(input()) for _ in range(n)]
print(n - len(lis(c)))