#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> g(N);
	vector<int> d(N);
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		d[y]++;
	}
	deque<int> q;
	vector<int> dp(N, -1e9);
	for (int i = 0; i < N; i++) {
		if (d[i] == 0) {
			q.push_back(i);
			dp[i] = 0;
		}
	}
	while (!q.empty()) {
		int u = q.back();
		q.pop_back();
		for (int v: g[u]) {
			dp[v] = max(dp[v], dp[u] + 1);
			d[v]--;
			if (d[v] == 0) {
				q.push_back(v);
			}
		}
	}
	int mx = 0;
	for (int i: dp) mx = max(mx, i);
	cout << mx << '\n';
}