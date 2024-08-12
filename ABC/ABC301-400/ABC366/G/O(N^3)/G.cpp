#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> g(N, vector<int>(N));
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	vector<long long> c(N);
	for (int i = 0; i < N; i++) {
		int k = -1;
		for (int j = 0; j < N; j++) {
			if (g[j][i] == 1 && all_of(g[j].begin(), g[j].begin() + i, [](int x) { return x == 0; })) {
				k = j;
				break;
			}
		}
		if (k == -1) {
			c[i] = 1LL << i;
			continue;
		}
		swap(g[i], g[k]);
		for (int j = 0; j < N; j++) {
			if (i != j && g[j][i] == 1) {
				for (int k = i; k < N; k++) {
					g[j][k] ^= g[i][k];
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (accumulate(g[i].begin(), g[i].end(), 0) == 1) {
			cout << "No\n";
			return 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (c[j] == 0 && g[i][j] == 1) {
				for (int k = 0; k < N; k++) {
					if (g[i][k] == 1) {
						c[j] ^= c[k];
					}
				}
			}
		}
	}
	cout << "Yes\n";
	for (int i = 0; i < N; i++) {
		cout << c[i] << ' ';
	}
	cout << '\n';
}