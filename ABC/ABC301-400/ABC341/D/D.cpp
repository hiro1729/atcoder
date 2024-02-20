#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll N, M, K;
	cin >> N >> M >> K;
	ll L = lcm(N, M);
	ll left = 0, right = 1LL << 60;
	while (left + 1 < right) {
		ll mid = (left + right) / 2;
		if (mid / N + mid / M - mid / L * 2 < K) {
			left = mid;
		} else {
			right = mid;
		}
	}
	cout << right << '\n';
}