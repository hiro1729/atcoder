class Comb:
	def __init__(self, N: int = 210000, mod: int = 1000000007):
		self.n = N
		self.mod = mod
		self.fac = [0] * (self.n + 1)
		self.invf = [0] * (self.n + 1)
		self.inv = [0] * (self.n + 1)
		self.fac[0] = 1
		self.fac[1] = 1
		self.invf[0] = 1
		self.invf[1] = 1
		self.inv[1] = 1
		for i in range(2, self.n + 1):
			self.fac[i] = self.fac[i - 1] * i % self.mod
			self.inv[i] = self.mod - self.inv[self.mod % i] * (self.mod // i) % self.mod
			self.invf[i] = self.invf[i - 1] * self.inv[i] % self.mod
	def F(self, N: int):
		if N < 0:
			return 0
		return self.fac[N]
	def C(self, N: int, K: int):
		if N < 0 or K < 0 or N < K:
			return 0
		return self.invf[K] * self.invf[N - K] % self.mod * self.fac[N] % self.mod
	def P(self, N: int, K: int):
		if N < 0 or K < 0 or N < K:
			return 0
		return self.invf[N - K] * self.fac[N] % self.mod
	def H(self, N: int, K: int):
		return self.C(N + K - 1, K)

R, C = map(int, input().split())
X, Y = map(int, input().split())
D, L = map(int, input().split())
c = Comb()
cnt = 0
cnt += c.C(X * Y, D + L)
cnt -= (c.C(X * (Y - 1), D + L) + c.C((X - 1) * Y, D + L)) * 2
cnt += c.C(X * (Y - 2), D + L) + c.C((X - 1) * (Y - 1), D + L) * 4 + c.C((X - 2) * Y, D + L)
cnt -= (c.C((X - 1) * (Y - 2), D + L) + c.C((X - 2) * (Y - 1), D + L)) * 2
if X >= 2 and Y >= 2:
	cnt += c.C((X - 2) * (Y - 2), D + L)
print(cnt * (R - X + 1) * (C - Y + 1) * c.C(D + L, D) % 1000000007)
