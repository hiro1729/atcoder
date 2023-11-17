#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> S, vector<int> T) {
	vector<int> ans;
	for (int i: S) {
		ans.push_back(T[i]);
	}
	return ans;
}

int main() {
	int N, M, D;
	cin >> N >> M >> D;
	vector<int> A(M);
	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}
	vector<vector<int>> dp(31, vector<int>(N));
	for (int i = 0; i < N; i++) {
		dp[0][i] = i;
	}
	for (int i = M - 1; i >= 0; i--) {
		swap(dp[0][A[i]], dp[0][A[i] - 1]);
	}
	for (int i = 0; i < 30; i++) {
		dp[i + 1] = f(dp[i], dp[i]);
	}
	vector<int> ans(N);
	for (int i = 0; i < N; i++) {
		ans[i] = i;
	}
	for (int i = 0; i < 31; i++) {
		if (D & (1 << i)) {
			ans = f(ans, dp[i]);
		}
	}
	for (int i: ans) {
		cout << i + 1 << '\n';
	}
}