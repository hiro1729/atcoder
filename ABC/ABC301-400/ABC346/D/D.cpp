#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	vector<int> C(N);
	for (int i = 0; i < N; i++) cin >> C[i];
	vector<ll> ac_00(N + 1), ac_01(N + 1), ac_10(N + 1), ac_11(N + 1);
	for (int i = 0; i < N; i++) {
		ac_00[i + 1] = ac_01[i] + (S[i] == '1' ? C[i] : 0);
		ac_01[i + 1] = ac_00[i] + (S[i] == '0' ? C[i] : 0);
	}
	for (int i = N - 1; i >= 0; i--) {
		ac_10[i] = ac_11[i + 1] + (S[i] == '1' ? C[i] : 0);
		ac_11[i] = ac_10[i + 1] + (S[i] == '0' ? C[i] : 0);
	}
	ll ans = 1LL << 60;
	for (int i = 1; i < N; i++) {
		ans = min(ans, ac_00[i] + ac_10[i]);
		ans = min(ans, ac_01[i] + ac_11[i]);
	}
	cout << ans << '\n';
}