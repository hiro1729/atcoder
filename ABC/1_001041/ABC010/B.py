N = int(input())
A = list(map(int, input().split()))
print(sum([0, 0, 1, 0, 1, 2, 3, 0, 1, 0, 1][i] for i in A))