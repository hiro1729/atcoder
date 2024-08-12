#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

int main() {
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> pairs(N);
	for (int i = 0; i < N; i++) {
		cin >> pairs[i].first >> pairs[i].second;
	}
	sort(pairs.begin(), pairs.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
		return x.second * (y.first - 1) > y.second * (x.first - 1);
	});
	vector<ll> dp(K + 1, -inf);
	dp[0] = 1;
	for (auto [a, b]: pairs) {
		vector<ll> ndp = dp;
		for (int j = 0; j < K; j++) {
			if (dp[j] != -inf) {
				ndp[j + 1] = max(ndp[j + 1], dp[j] * a + b);
			}
		}
		dp = ndp;
	}
	cout << dp[K] << '\n';
}