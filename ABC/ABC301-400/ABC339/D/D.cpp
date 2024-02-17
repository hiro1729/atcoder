#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	int player1_x = -1, player1_y = -1, player2_x = -1, player2_y = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (S[i][j] == 'P') {
				if (player1_x == -1 && player1_y == -1) {
					player1_x = i;
					player1_y = j;
				} else {
					player2_x = i;
					player2_y = j;
				}
			}
		}
	}
	vector<vector<vector<vector<int>>>> d(N, vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, -1))));
	d[player1_x][player1_y][player2_x][player2_y] = 0;
	deque<tuple<int, int, int, int>> q;
	q.push_back({player1_x, player1_y, player2_x, player2_y});
	while (!q.empty()) {
		auto [now1_x, now1_y, now2_x, now2_y] = q.front();
		q.pop_front();
		for (auto [dx, dy]: dxy) {
			int next1_x = now1_x + dx, next1_y = now1_y + dy, next2_x = now2_x + dx, next2_y = now2_y + dy;
			if (!(0 <= next1_x && next1_x < N && 0 <= next1_y && next1_y < N) || S[next1_x][next1_y] == '#') {
				next1_x = now1_x;
				next1_y = now1_y;
			}
			if (!(0 <= next2_x && next2_x < N && 0 <= next2_y && next2_y < N) || S[next2_x][next2_y] == '#') {
				next2_x = now2_x;
				next2_y = now2_y;
			}
			if (d[next1_x][next1_y][next2_x][next2_y] >= 0) {
				continue;
			}
			d[next1_x][next1_y][next2_x][next2_y] = d[now1_x][now1_y][now2_x][now2_y] + 1;
			if (next1_x == next2_x && next1_y == next2_y) {
				cout << d[next1_x][next1_y][next2_x][next2_y] << '\n';
				return 0;
			}
			q.push_back({next1_x, next1_y, next2_x, next2_y});
		}
	}
	cout << "-1\n";
}