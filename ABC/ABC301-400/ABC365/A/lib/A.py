from calendar import isleap
Y = int(input())
if isleap(Y):
	print(366)
else:
	print(365)