S = input()
print("Yes" if S[0].isupper() and all(i.islower() for i in S[1:]) else "No")