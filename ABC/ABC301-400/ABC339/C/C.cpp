#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<ll> ac = {0};
	ll m = 0;
	for (int i = 0; i < N; i++) {
		ll A;
		cin >> A;
		ac.push_back(ac.back() + A);
		m = min(m, ac.back());
	}
	cout << ac.back() - m << '\n';
}