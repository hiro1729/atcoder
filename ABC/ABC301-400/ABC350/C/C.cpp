#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
		B[A[i]] = i;
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < N; i++) {
		if (A[i] != i) {
			int j = B[i];
			swap(A[i], A[j]);
			swap(B[A[i]], B[A[j]]);
			ans.push_back({i, j});
		}
	}
	cout << ans.size() << '\n';
	for (auto [i, j]: ans) {
		cout << i + 1 << ' ' << j + 1 << '\n';
	}
}