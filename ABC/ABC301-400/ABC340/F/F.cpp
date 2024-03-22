#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> extgcd(ll a, ll b) {
	if (b == 0) {
		return {1, 0};
	} else {
		auto [x, y] = extgcd(b, a % b);
		return {y, x - a / b * y};
	}
}

int main() {
	ll X, Y;
	cin >> X >> Y;
	ll g = gcd(X, Y);
	if (g > 2) {
		cout << "-1\n";
		return 0;
	}
	auto [a, b] = extgcd(Y, -X);
	cout << a * 2 / g << ' ' << b * 2 / g << '\n';
}