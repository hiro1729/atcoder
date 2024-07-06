#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
	int N, M;
	cin >> N >> M;
	dsu uf(N);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		A--;
		B--;
		uf.merge(A, B);
	}
	ll ans = -M;
	for (auto v: uf.groups()) {
		ll x = v.size();
		ans += x * (x - 1) / 2;
	}
	cout << ans << '\n';
}