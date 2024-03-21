#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll b = 1e9;

int main() {
	random_device rd;
	mt19937 eng(rd());
	vector<ll> mods(5);
	for (int i = 0; i < 5; i++) {
		mods[i] = (eng() % b) + b;
	}
	int N;
	cin >> N;
	vector<array<ll, 5>> A_mod(N);
	map<array<ll, 5>, int> cnt;
	for (int i = 0; i < N; i++) {
		string A;
		cin >> A;
		for (int j = 0; j < 5; j++) {
			ll Amod = 0;
			for (char c: A) {
				Amod = (Amod * 10 + (c - '0')) % mods[j];
			}
			A_mod[i][j] = Amod;
		}
		cnt[A_mod[i]]++;
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			array<ll, 5> A_ij;
			for (int k = 0; k < 5; k++) {
				A_ij[k] = A_mod[i][k] * A_mod[j][k] % mods[k];
			}
			ans += cnt[A_ij];
		}
	}
	cout << ans << '\n';
}