N, X, Y = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
A.sort(reverse = True)
B.sort(reverse = True)
sA = 0
sB = 0
cA = 0
cB = 0
for a in A:
	sA += a
	cA += 1
	if sA > X:
		break
for b in B:
	sB += b
	cB += 1
	if sB > Y:
		break
print(min(cA, cB))