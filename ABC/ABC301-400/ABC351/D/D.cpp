/*
磁石でもなく、磁石に隣接しないマスの連結成分ごとに計算する
*/

#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

const pair<int, int> dxy4[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (int i = 0; i < H; i++) {
		cin >> S[i];
	}
	// T[i][j] = 1 ならば磁石のマス、T[i][j] = 2 ならば磁石に隣接するマス、T[i][j] = 0 ならば磁石でもなく、磁石に隣接もしないマス
	vector<vector<int>> T(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') {
				T[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') {
				for (auto [dx, dy]: dxy4) {
					int nx = i + dx, ny = j + dy;
					if (0 <= nx && nx < H && 0 <= ny && ny < W && T[nx][ny] != 1) {
						T[nx][ny] = 2;
					}
				}
			}
		}
	}
	dsu uf(H * W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (T[i][j] == 0) {
				for (auto [dx, dy]: dxy4) {
					int nx = i + dx, ny = j + dy;
					if (0 <= nx && nx < H && 0 <= ny && ny < W && T[nx][ny] == 0) {
						uf.merge(i * W + j, nx * W + ny);
					}
				}
			}
		}
	}
	// 磁石でもなく、磁石に隣接もしないマスの連結成分の leader に答えを加算
	// 磁石に隣接するマスから、それに隣接し、磁石でもなく磁石に隣接しないマスの leader に答えを加算する
	// 下のときは、重複に注意する
	map<int, int> cnt;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (T[i][j] == 0) {
				cnt[uf.leader(i * W + j)]++;
			}
			if (T[i][j] == 2) {
				set<int> leaders;
				for (auto [dx, dy]: dxy4) {
					int nx = i + dx, ny = j + dy;
					if (0 <= nx && nx < H && 0 <= ny && ny < W && T[nx][ny] == 0) {
						leaders.insert(uf.leader(nx * W + ny));
					}
				}
				for (int l: leaders) {
					cnt[l]++;
				}
			}
		}
	}
	int ans = 0;
	for (auto [i, j]: cnt) {
		ans = max(ans, j);
	}
	cout << max(1, ans) << '\n';
}