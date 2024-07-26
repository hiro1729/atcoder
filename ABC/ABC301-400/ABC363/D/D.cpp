#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll N, cnt = 0, x = 9;
	cin >> N;
	for (int i = 0; i < 35; i++) {
		if (N < cnt + x) {
			ll t = x / 9 + N - cnt - 2;
			string u = to_string(t);
			reverse(u.begin(), u.end());
			if (i % 2 == 0) {
				cout << t << u.substr(1) << '\n';
			} else {
				cout << t << u << '\n';
			}
			break;
		}
		cnt += x;
		if (i % 2 == 1) {
			x *= 10;
		}
	}
}