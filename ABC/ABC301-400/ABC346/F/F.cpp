#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll N;
	string S, T;
	cin >> N >> S >> T;
	int K = S.size();
	vector<vector<int>> cnt(26, vector<int>(K + 1)), x(26);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 26; j++) cnt[j][i + 1] = cnt[j][i];
		cnt[S[i] - 'a'][i + 1]++;
		x[S[i] - 'a'].push_back(i);
	}
	for (char c: T) {
		if (cnt[c - 'a'][K] == 0) {
			cout << "0\n";
			return 0;
		}
	}
	ll le = 0, ri = 1e17 + 10;
	while (le + 1 < ri) {
		ll mi = (le + ri) >> 1;
		ll now = 0;
		for (char c: T) {
			ll p = cnt[c - 'a'][K] * (now / K) + cnt[c - 'a'][now % K] + mi;
			now = (p - 1) / cnt[c - 'a'][K] * K + x[c - 'a'][(p - 1) % cnt[c - 'a'][K]] + 1;
			if (now > K * N) break;
		}
		if (now <= K * N) le = mi;
		else ri = mi;
	}
	cout << le << '\n';
}