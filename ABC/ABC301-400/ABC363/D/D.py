N = int(input())
cnt = 0
for i in range(35):
	x = 9 * 10 ** (i // 2)
	if N < cnt + x:
		t = str(10 ** (i // 2) + N - cnt - 2)
		if i % 2 == 0:
			print(t + t[::-1][1:])
		else:
			print(t + t[::-1])
		break
	cnt += x