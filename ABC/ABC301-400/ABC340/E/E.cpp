#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
using ll = long long;

ll op(ll a, ll b) {
	return a + b;
}

ll e() {
	return 0;
}

ll mapping(ll f, ll x) {
	return f + x;
}

ll composition(ll f, ll g) {
	return f + g;
}

ll id() {
	return 0;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	lazy_segtree<ll, op, e, ll, mapping, composition, id> lseg(A);
	while (M--) {
		int B;
		cin >> B;
		ll C = lseg.get(B);
		lseg.set(B, 0);
		lseg.apply(0, N, C / N);
		C %= N;
		if (B + C < N) {
			lseg.apply(B + 1, B + C + 1, 1);
		} else {
			lseg.apply(B + 1, N, 1);
			lseg.apply(0, B + C + 1 - N, 1);
		}
	}
	for (int i = 0; i < N; i++) {
		cout << lseg.get(i) << ' ';
	}
}