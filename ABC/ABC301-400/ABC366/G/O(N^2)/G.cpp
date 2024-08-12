#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, M;
	cin >> N >> M;
	vector<ll> g(N);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u] |= 1LL << v;
		g[v] |= 1LL << u;
	}
	vector<ll> c(N);
	ll C = 0;
	for (int i = 0; i < N; i++) {
		int k = -1;
		for (int j = 0; j < N; j++) {
			if ((g[j] >> i) & 1 == 1 && g[j] >> i << i == g[j]) {
				k = j;
				break;
			}
		}
		if (k == -1) {
			c[i] = 1LL << i;
			C |= c[i];
			continue;
		}
		swap(g[i], g[k]);
		for (int j = 0; j < N; j++) {
			if (i != j && (g[j] >> i) & 1 == 1) {
				g[j] ^= g[i];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (__builtin_popcountll(g[i]) == 1) {
			cout << "No\n";
			return 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (c[j] == 0 && (g[i] >> j) & 1 == 1) {
				c[j] ^= g[i] & C;
			}
		}
	}
	cout << "Yes\n";
	for (int i = 0; i < N; i++) {
		cout << c[i] << ' ';
	}
	cout << '\n';
}