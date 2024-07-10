// 各辺の長さ * 2 - 木の直径

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> g(N);
	ll s = 0;
	for (int i = 0; i < N - 1; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		A--;
		B--;
		g[A].push_back({B, C});
		g[B].push_back({A, C});
		s += 2 * C;
	}
	// uからの {直径, 頂点} を返す関数
	auto dfs = [&](auto self, int u, int p) -> pair<ll, int> {
		pair<ll, int> rt = {0, u};
		for (auto [e, c]: g[u]) {
			if (e == p) {
				continue;
			}
			pair<ll, int> co = self(self, e, u);
			rt = max(rt, {co.first + c, co.second});
		}
		return rt;
	};
	pair<ll, int> p = dfs(dfs, 0, -1);
	pair<ll, int> q = dfs(dfs, p.second, -1);
	cout << s - q.first << '\n';
}