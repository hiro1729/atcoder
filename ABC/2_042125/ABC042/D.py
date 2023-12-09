class Comb:
	def __init__(self, N, mod = 1000000007):
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
	def F(self, N):
		return self.fac[N]
	def C(self, N, K):
		return self.invf[K] * self.invf[N - K] % self.mod * self.fac[N] % self.mod
	def P(self, N, K):
		return self.invf[N - K] * self.fac[N] % self.mod
	def H(self, N, K):
		return self.invf[K] * self.invf[N - 1] % self.mod * self.fac[N + K - 1] % self.mod

H, W, A, B = map(int, input().split())
c = Comb(210000)
ans = c.C(H + W - 2, H - 1)
for i in range(B):
	ans -= c.C(H - A - 1 + i, H - A - 1) * c.C(A - 1 + W - 1 - i, A - 1)
print(ans % 1000000007)