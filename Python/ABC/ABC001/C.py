deg, dis = map(int, input().split())
w = -1
if dis < 15:
    w = 0
elif dis < 93:
    w = 1
elif dis < 201:
    w = 2
elif dis < 327:
    w = 3
elif dis < 477:
    w = 4
elif dis < 645:
    w = 5
elif dis < 831:
    w = 6
elif dis < 1029:
    w = 7
elif dis < 1245:
    w = 8
elif dis < 1467:
    w = 9
elif dis < 1707:
    w = 10
elif dis < 1959:
    w = 11
else:
    w = 12
if w == 0:
    print("C 0")
else:
    if deg <= 112:
        print("N ", end = "")
    elif deg <= 337:
        print("NNE ", end="")
    elif deg <= 562:
        print("NE ", end="")
    elif deg <= 787:
        print("ENE ", end="")
    elif deg <= 1012:
        print("E ", end="")
    elif deg <= 1237:
        print("ESE ", end="")
    elif deg <= 1462:
        print("SE ", end="")
    elif deg <= 1687:
        print("SSE ", end="")
    elif deg <= 1912:
        print("S ", end="")
    elif deg <= 2137:
        print("SSW ", end="")
    elif deg <= 2362:
        print("SW ", end="")
    elif deg <= 2587:
        print("WSW ", end="")
    elif deg <= 2812:
        print("W ", end="")
    elif deg <= 3037:
        print("WNW ", end="")
    elif deg <= 3262:
        print("NW ", end="")
    elif deg <= 3487:
        print("NNW ", end="")
    else:
        print("N ", end="")
    print(w)