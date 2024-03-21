#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;

int op(int a, int b) {
	return max(a, b);
}

int e() {
	return 0;
}

int main() {
	int N, D, A, d = 500000;
	cin >> N >> D;
	segtree<int, op, e> seg(d * 3);
	for (int i = 0; i < N; i++) {
		cin >> A;
		seg.set(A + d, seg.prod(A - D + d, A + D + 1 + d) + 1);
	}
	cout << seg.all_prod() << '\n';
}