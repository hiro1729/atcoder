#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
	int N, X, Y;
	cin >> N >> X >> Y;
	vector<vector<int>> dp(N + 1, vector<int>(X + 1, inf));
	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		for (int j = i; j >= 0; j--) {
			for (int k = X; k >= A; k--) {
				if (dp[j][k - A] < inf) {
					dp[j + 1][k] = min(dp[j + 1][k], dp[j][k - A] + B);
				}
			}
		}
	}
	for (int i = N; i >= 0; i--) {
		for (int j = 0; j <= X; j++) {
			if (dp[i][j] <= Y) {
				cout << min(i + 1, N) << '\n';
				return 0;
			}
		}
	}
}