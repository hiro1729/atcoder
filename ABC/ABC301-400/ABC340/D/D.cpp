#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, ll>>> g(N);
	for (int i = 0; i < N - 1; i++) {
		ll A, B; int X;
		cin >> A >> B >> X;
		g[i].push_back({i + 1, A});
		g[i].push_back({X - 1, B});
	}
	vector<ll> dist(N, 1LL << 60);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[0] = 0;
	pq.push({0, 0});
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (dist[u] < d) continue;
		for (auto [v, c]: g[u]) {
			if (dist[u] + c < dist[v]) {
				dist[v] = dist[u] + c;
				pq.push({dist[v], v});
			}
		}
	}
	cout << dist[N - 1] << '\n';
}