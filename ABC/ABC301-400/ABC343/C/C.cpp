#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;
	vector<ll> cubes;
	for (ll x = 0; x <= 1000000; x++) {
		ll x3 = x * x * x;
		string x3_str = to_string(x3), x3_str_2 = x3_str;
		reverse(x3_str_2.begin(), x3_str_2.end());
		if (x3_str == x3_str_2) {
			cubes.push_back(x3);
		}
	}
	ll ans = 0;
	for (ll cube: cubes) {
		if (cube <= N) {
			ans = cube;
		}
	}
	cout << ans << '\n';
}