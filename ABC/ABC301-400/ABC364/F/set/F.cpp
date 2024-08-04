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
	set<int> st;
	for (int i = 0; i < N - 1; i++) {
		st.insert(i);
	}
	ll ans = 0;
	for (auto [C, L, R]: edges) {
		int cnt = 0;
		while (true) {
			auto bs = st.lower_bound(L);
			if (bs != st.end() && *bs < R) {
				cnt++;
				st.erase(bs);
			} else {
				break;
			}
		}
		ans += (cnt + 1) * C;
	}
	cout << (st.size() == 0 ? ans : -1) << '\n';
}