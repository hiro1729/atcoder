#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int H, W, M;
	cin >> H >> W >> M;
	vector<int> T(M), A(M), X(M);
	for (int i = 0; i < M; i++) {
		cin >> T[i] >> A[i] >> X[i];
		A[i]--;
	}
	vector<bool> R(H), C(W);
	map<int, ll> mp;
	int r = H, c = W;
	for (int i = M - 1; i >= 0; i--) {
		if (T[i] == 1 && !R[A[i]]) {
			mp[X[i]] += c; r--;
			R[A[i]] = true;
		}
		if (T[i] == 2 && !C[A[i]]) {
			mp[X[i]] += r; c--;
			C[A[i]] = true;
		}
	}
	ll not_zero = (ll)H * W;
	for (auto [c, x]: mp) {
		not_zero -= x;
	}
	mp[0] += not_zero;
	vector<pair<int, ll>> ans;
	for (auto [c, x]: mp) {
		if (x > 0) {
			ans.push_back({c, x});
		}
	}
	cout << ans.size() << '\n';
	for (auto [c, x]: ans) {
		cout << c << ' ' << x << '\n';
	}
}