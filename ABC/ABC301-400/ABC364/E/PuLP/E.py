from pulp import *

N, X, Y = map(int, input().split())
A = [0] * N
B = [0] * N
for i in range(N):
	A[i], B[i] = map(int, input().split())
m = LpProblem(sense = LpMaximize)
x = [LpVariable('x_' + str(i), cat = LpBinary) for i in range(N)]
m += sum(x)
m += sum([A[i] * x[i] for i in range(N)]) <= X
m += sum([B[i] * x[i] for i in range(N)]) <= Y
m.solve(PULP_CBC_CMD(msg=0))
s = int(sum([value(x[i]) for i in range(N)]))
print(min(s + 1, N))