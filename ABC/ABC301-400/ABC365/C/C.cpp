#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1000000000;

int main() {
	int N;
	ll M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int le = 0, ri = inf + 1;
	while (le + 1 < ri) {
		int mi = (le + ri) / 2;
		ll s = 0;
		for (int i: A) {
			s += min(i, mi);
		}
		if (s <= M) {
			le = mi;
		} else {
			ri = mi;
		}
	}
	if (le < inf) {
		cout << le << '\n';
	} else {
		cout << "infinite\n";
	}
}