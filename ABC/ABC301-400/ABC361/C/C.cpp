#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans = 1e9;
	for (int i = 0; i < K + 1; i++) {
		ans = min(ans, A[i + N - K - 1] - A[i]);
	}
	cout << ans << '\n';
}