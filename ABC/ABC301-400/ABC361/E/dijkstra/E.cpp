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
	auto dijkstra_calc = [&](int u) -> pair<ll, int> {
		vector<ll> dist(N, 1e18);
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pque;
		dist[u] = 0;
		pque.push({0, u});
		while (!pque.empty()) {
			auto [d, e] = pque.top();
			pque.pop();
			if (dist[e] < d) {
				continue;
			}
			for (auto [v, c]: g[e]) {
				if (dist[e] + c < dist[v]) {
					dist[v] = dist[e] + c;
					pque.push({dist[v], v});
				}
			}
		}
		pair<ll, int> rt = {0, u};
		for (int i = 0; i < N; i++) {
			if (rt.first < dist[i]) {
				rt = {dist[i], i};
			}
		}
		return rt;
	};
	pair<ll, int> p = dijkstra_calc(0);
	pair<ll, int> q = dijkstra_calc(p.second);
	cout << s - q.first << '\n';
}