#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int Q;
	cin >> Q;
	vector<int> B(Q);
	for (int i = 0; i < Q; i++) {
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	for (int i: B) {
		int x = lower_bound(A.begin(), A.end(), i) - A.begin();
		int ans = 1e9;
		if (x > 0) {
			ans = min(ans, i - A[x - 1]);
		}
		if (x < N) {
			ans = min(ans, A[x] - i);
		}
		cout << ans << '\n';
	}
}