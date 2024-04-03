#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, H, W;
	cin >> N >> H >> W;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	for (int i = 0; i < (1 << N); i++) {
		vector<int> P;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) P.push_back(j);
		}
		int s = 0;
		for (int j: P) s += A[j] * B[j];
		if (s != H * W) continue;
		do {
			for (int j = 0; j < (1 << P.size()); j++) {
				bool ok = true;
				vector<vector<bool>> place(H, vector<bool>(W));
				for (int p = 0; p < P.size(); p++) {
					int x = -1, y = -1;
					for (int k = 0; k < H; k++) {
						for (int l = 0; l < W; l++) {
							if (!place[k][l]) {
								x = k; y = l;
								break;
							}
						}
						if (x != -1) break;
					}
					if (j & (1 << p)) {
						for (int k = x; k < x + A[P[p]]; k++) {
							for (int l = y; l < y + B[P[p]]; l++) {
								if (k >= H || l >= W || place[k][l]) {
									ok = false;
									break;
								}
								place[k][l] = true;
							}
							if (!ok) break;
						}
					} else {
						for (int k = x; k < x + B[P[p]]; k++) {
							for (int l = y; l < y + A[P[p]]; l++) {
								if (k >= H || l >= W || place[k][l]) {
									ok = false;
									break;
								}
								place[k][l] = true;
							}
							if (!ok) break;
						}
					}
					if (!ok) break;
				}
				if (ok) {
					cout << "Yes\n";
					return 0;
				}
			}
		} while (next_permutation(P.begin(), P.end()));
	}
	cout << "No\n";
}