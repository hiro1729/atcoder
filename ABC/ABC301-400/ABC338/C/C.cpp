#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<ll> Q(N), A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> Q[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	ll ans = 0;
	for (int i = 0; i <= 1000000; i++) {
		bool ok = true;
		ll now = 1000000;
		for (int j = 0; j < N; j++) {
			if (Q[j] < A[j] * i) {
				ok = false;
			}
			if (B[j] > 0) {
				now = min(now, (Q[j] - A[j] * i) / B[j]);
			}
		}
		if (ok) {
			ans = max(ans, i + now);
		}
	}
	cout << ans << '\n';
}