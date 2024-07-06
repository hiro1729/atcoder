#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N, 1);
	for (int i = 0; i < Q; i++) {
		int T;
		cin >> T;
		T--;
		A[T] ^= 1;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += A[i];
	}
	cout << ans << '\n';
}