#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
using ll = long long;

struct S {
	int val, len;
};

S op(S a, S b) {
	return {a.val + b.val, a.len + b.len};
}

S e() {
	return {0, 0};
}

S mapping(int f, S x) {
	if (f != -1) {
		x.val = x.len * f;
	}
	return x;
}

int composition(int f, int g) {
	return (f == -1 ? g : f);
}

int id() {
	return -1;
}

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<tuple<ll, int, int>> edges(Q);
	for (int i = 0; i < Q; i++) {
		ll C;
		int L, R;
		cin >> L >> R >> C;
		edges[i] = {C, L - 1, R - 1};
	}
	sort(edges.begin(), edges.end());
	lazy_segtree<S, op, e, int, mapping, composition, id> lseg(vector<S>(N - 1, {1, 1}));
	ll ans = 0;
	for (auto [C, L, R]: edges) {
		int cnt = lseg.prod(L, R).val;
		lseg.apply(L, R, 0);
		ans += (cnt + 1) * C;
	}
	cout << (lseg.all_prod().val == 0 ? ans: -1) << '\n';
}