#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<vector<int>>> B(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1)));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				cin >> B[i][j][k];
			}
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k < N; k++) {
				B[i][j][k + 1] += B[i][j][k];
			}
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= N; k++) {
				B[i][j + 1][k] += B[i][j][k];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= N; k++) {
				B[i + 1][j][k] += B[i][j][k];
			}
		}
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int lx, rx, ly, ry, lz, rz;
		cin >> lx >> rx >> ly >> ry >> lz >> rz;
		lx--;
		ly--;
		lz--;
		int ans = 0;
		ans += B[rx][ry][rz];
		ans -= B[rx][ry][lz];
		ans -= B[rx][ly][rz];
		ans += B[rx][ly][lz];
		ans -= B[lx][ry][rz];
		ans += B[lx][ry][lz];
		ans += B[lx][ly][rz];
		ans -= B[lx][ly][lz];
		cout << ans << '\n';
	}
}