s = input()
t = input()
for i, j in zip(s, t):
    if i != j:
        ok = False
        if i == '@':
            if j in "atcoder":
                ok = True
        elif j == '@':
            if i in "atcoder":
                ok = True
        if not ok:
            exit(print("You will lose"))
print("You can win")