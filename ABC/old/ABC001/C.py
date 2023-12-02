Deg, Dis = map(int, input().split())
Dir = ["NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"][(Deg - 113) % 3600 // 225]
W = 0
if Dis < 15:
	Dir = "C"
elif Dis < 93:
	W = 1
elif Dis < 201:
	W = 2
elif Dis < 327:
	W = 3
elif Dis < 477:
	W = 4
elif Dis < 645:
	W = 5
elif Dis < 831:
	W = 6
elif Dis < 1029:
	W = 7
elif Dis < 1245:
	W = 8
elif Dis < 1467:
	W = 9
elif Dis < 1707:
	W = 10
elif Dis < 1959:
	W = 11
else:
	W = 12
print(Dir, W)