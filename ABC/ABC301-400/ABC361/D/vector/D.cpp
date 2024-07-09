#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	string S, T;
	cin >> N >> S >> T;
	int Sn = 0, Tn = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'B') {
			Sn |= 1 << i;
		}
		if (T[i] == 'B') {
			Tn |= 1 << i;
		}
	}
	vector<vector<int>> dist(N + 1, vector<int>(1 << (N + 2)));
	deque<pair<int, int>> que;
	que.push_back({N, Sn});
	dist[N][Sn] = 1;
	while (!que.empty()) {
		auto [d, A] = que.front();
		que.pop_front();
		for (int i = 0; i < N + 1; i++) {
			if (i != d - 1 && i != d && i != d + 1) {
				int B = A;
				B ^= ((A >> i) & 3) << d;
				B ^= (A & (3 << i));
				if (dist[i][B] == 0 || dist[d][A] + 1 < dist[i][B]) {
					dist[i][B] = dist[d][A] + 1;
					que.push_back({i, B});
				}
			}
		}
	}
	int ans = dist[N][Tn];
	cout << ans - 1 << '\n';
}