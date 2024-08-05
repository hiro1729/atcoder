#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
	bitset<200001> bs(string(200001, '1'));
	ll ans = 0;
	for (auto [C, L, R]: edges) {
		int cnt = 0;
		while (true) {
			int nx = bs._Find_next(L - 1);
			if (nx < R) {
				cnt++;
				bs.reset(nx);
			} else {
				break;
			}
		}
		ans += (cnt + 1) * C;
	}
	cout << (bs._Find_first() >= N - 1 ? ans: -1) << '\n';
}