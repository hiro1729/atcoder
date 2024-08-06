N = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(27):
	B = 0
	C = [1, 0]
	for j in A:
		B ^= (j >> i) & 1
		C[B] += 1
	ans += C[0] * C[1] << i
print(ans - sum(A))