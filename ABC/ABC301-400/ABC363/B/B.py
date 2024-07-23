N, T, P = map(int, input().split())
L = list(map(int, input().split()))
L.sort(reverse = True)
print(max(T - L[P - 1], 0))