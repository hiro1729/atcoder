// https://atcoder.jp/contests/abc351/editorial/9897

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
	vector<int> B = A;
	sort(B.begin(), B.end());
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += (ll)i * B[i] - (ll)(N - 1 - i) * A[i];
	}
	cout << ans << '\n';
}