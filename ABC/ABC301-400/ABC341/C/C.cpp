#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W, N;
	string T;
	cin >> H >> W >> N >> T;
	vector<string> S(H);
	for (int i = 0; i < H; i++) {
		cin >> S[i];
	}
	int ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') {
				continue;
			}
			int nowx = i, nowy = j;
			bool ok = true;
			for (char c: T) {
				if (c == 'U') {
					nowx--;
				}
				if (c == 'D') {
					nowx++;
				}
				if (c == 'L') {
					nowy--;
				}
				if (c == 'R') {
					nowy++;
				}
				if (S[nowx][nowy] == '#') {
					ok = false;
					break;
				}
			}
			if (ok) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}