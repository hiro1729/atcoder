n = int(input())
rain = [False] * 289
for _ in range(n):
    se = input()
    sh = int(se[0:2])
    sm = int(se[2:4])
    eh = int(se[5:7])
    em = int(se[7:9])
    smr = (sm // 5) * 5
    emr = 0
    if em != 0:
        emr = ((em - 1) // 5 + 1) * 5
    ssm = sh * 60 + smr
    sem = eh * 60 + emr
    for j in range(ssm // 5, sem // 5):
        rain[j] = True
now = False
for i in range(289):
    if rain[i]:
        if not now:
            now = True
            h = i // 12
            m = i % 12 * 5
            if h < 10:
                print(0, end="")
            print(h, end="")
            if m < 10:
                print(0, end="")
            print(str(m) + '-', end="")
    else:
        if now:
            now = False
            h = i // 12
            m = i % 12 * 5
            if h < 10:
                print(0, end="")
            print(h, end="")
            if m < 10:
                print(0, end="")
            print(m)
    if i == 288 and now == True:
        print(2400)