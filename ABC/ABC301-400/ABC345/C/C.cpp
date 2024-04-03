#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string S;
	cin >> S;
	vector<int> cnt(26);
	for (char c: S) cnt[c - 'a']++;
	ll ans = (ll)S.size() * (S.size() - 1) / 2, b = 0;
	for (int i: cnt) {
		if (i >= 2) {
			ans -= (ll)i * (i - 1) / 2;
			b = 1;
		}
	}
	cout << ans + b << '\n';
}