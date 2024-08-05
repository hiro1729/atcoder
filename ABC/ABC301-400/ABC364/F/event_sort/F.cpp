#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<tuple<int, ll, bool>> events;
	ll ans = 0;
	for (int i = 0; i < Q; i++) {
		ll C;
		int L, R;
		cin >> L >> R >> C;
		L--;
		R--;
		events.push_back({L, C, false});
		events.push_back({R, C, true});
		ans += C;
	}
	sort(events.begin(), events.end());
	int ind = 0;
	multiset<int> ms;
	for (int i = 0; i < N - 1; i++) {
		while (ind < events.size() && get<0>(events[ind]) == i) {
			if (!get<2>(events[ind])) {
				ms.insert(get<1>(events[ind]));
			} else {
				ms.erase(ms.find(get<1>(events[ind])));
			}
			ind++;
		}
		if (ms.empty()) {
			cout << -1 << '\n';
			return 0;
		}
		ans += *ms.begin();
	}
	cout << ans << '\n';
}