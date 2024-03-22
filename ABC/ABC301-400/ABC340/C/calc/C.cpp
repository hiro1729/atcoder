#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;
	int c = 60;
	for (; c >= 0; c--) {
		if ((1LL << c) <= N) break;
	}
	cout << ((ll)c << c) + (c + 2) * (N - (1LL << c)) << '\n';
}