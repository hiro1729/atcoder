N = int(input())
A = list(map(int, input().split()))
B = A[:]
B.sort(reverse = True)
print(A.index(B[1]) + 1)