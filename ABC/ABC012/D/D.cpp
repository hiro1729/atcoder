#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> d(n, vector<int>(n, 1e9));
	for (int i = 0; i < n; i++) {
		d[i][i] = 0;
	}
	while (m--) {
		int a, b, t;
		cin >> a >> b >> t;
		a--; b--;
		d[a][b] = t;
		d[b][a] = t;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		int now = 0;
		for (int j: d[i]) now = max(now, j);
		ans = min(ans, now);
	}
	cout << ans << '\n';
}