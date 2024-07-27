N = int(input())
S = [input() for _ in range(N)]
for i in range(N - 2):
	if S[i] == S[i + 1] == "sweet":
		print("No")
		exit()
print("Yes")