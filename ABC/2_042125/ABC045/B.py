Sa = input()
Sb = input()
Sc = input()
now = 'a'
ia = 0
ib = 0
ic = 0
while True:
	if now == 'a':
		if ia == len(Sa):
			exit(print('A'))
		now = Sa[ia]
		ia += 1
	elif now == 'b':
		if ib == len(Sb):
			exit(print('B'))
		now = Sb[ib]
		ib += 1
	elif now == 'c':
		if ic == len(Sc):
			exit(print('C'))
		now = Sc[ic]
		ic += 1