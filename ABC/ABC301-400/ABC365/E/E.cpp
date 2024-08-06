#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	ll ans = 0;
	for (int i = 0; i < 27; i++) {
		int B = 0;
		int C[] = {1, 0};
		for (int j: A) {
			B ^= (j >> i) & 1;
			C[B]++;
		}
		ans += (ll)C[0] * C[1] << i;
	}
	cout << ans - accumulate(A.begin(), A.end(), 0LL) << '\n';
}