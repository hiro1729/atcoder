#include <bits/stdc++.h>
using namespace std;

struct LCA {
public:
	int n, ln;
	vector<int> depth, dist;
	vector<vector<int>> anc, edges;
	LCA(int n) : n(n), depth(n, 0), dist(n, 0), edges(n) {
		ln = 0; while ((1 << ln) < n) ln++;
		anc = vector<vector<int>>(ln, vector<int>(n, -1));
	}
	void add_edge(int u, int v) {
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	void build(int rt = 0) {
		queue<int> q;
		q.push(rt);
		while (!q.empty()) {
			int cr = q.front();
			q.pop();
			for (int nx: edges[cr]) {
				if (anc[0][nx] != cr && anc[0][cr] != nx) {
					anc[0][nx] = cr;
					depth[nx] = depth[cr] + 1;
					dist[nx] = dist[cr] + 1;
					q.push(nx);
				}
			}
		}
		for (int k = 1; k < ln; k++) {
			for (int i = 0; i < n; i++) {
				if (anc[k - 1][i] == -1) {
					anc[k][i] = -1;
				} else {
					anc[k][i] = anc[k - 1][anc[k - 1][i]];
				}
			}
		}
	}
	int lca(int u, int v) {
		if (depth[u] > depth[v]) {
			swap(u, v);
		}
		for (int k = ln - 1; k >= 0; k--) {
			if (((depth[v] - depth[u]) >> k) & 1) {
				v = anc[k][v];
			}
		}
		if (u == v) {
			return u;
		}
		for (int k = ln - 1; k >= 0; k--) {
			if (anc[k][u] != anc[k][v]) {
				u = anc[k][u];
				v = anc[k][v];
			}
		}
		return anc[0][u];
	}
	int distance(int u, int v) {
		return dist[u] + dist[v] - 2 * dist[lca(u, v)];
	}
};

int main() {
	int N;
	cin >> N;
	LCA g(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g.add_edge(a, b);
	}
	g.build();
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << g.distance(a, b) + 1 << '\n';
	}
}