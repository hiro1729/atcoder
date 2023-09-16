#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
	ll n, d, x, y;
	cin >> n >> d >> x >> y;
	if (x % d || y % d) {
		cout << "0.0\n";
		return 0;
	}
	x /= d;
	y /= d;
	if ((x + y + n) % 2 || abs(x + y) > n || abs(x - y) > n) {
		cout << "0.0\n";
		return 0;
	}
	ll a = (x + y + n) / 2, b = (x - y + n) / 2;
	vector<vector<ld>> c(n + 1);
	for (int i = 0; i < n + 1; i++) {
		c[i].resize(i + 1);
		if (i == 0) {
			c[0][0] = 1.0;
			continue;
		}
		for (int j = 0; j <= i; j++) {
			if (j) c[i][j] += c[i - 1][j - 1];
			if (j < i) c[i][j] += c[i - 1][j];
			c[i][j] /= 2;
		}
	}
	cout << fixed << setprecision(20) << c[n][a] * c[n][b] << '\n';
}