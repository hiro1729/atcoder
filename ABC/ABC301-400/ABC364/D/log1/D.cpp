#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a.begin(), a.end());
	while (Q--) {
		int b, k; cin >> b >> k;
		int le = -1, ri = N - k + 1;
		while (le + 1 < ri) {
			int mi = (le + ri) / 2;
			if (b - a[mi] >= a[mi + k - 1] - b) {
				le = mi;
			} else {
				ri = mi;
			}
		}
		int ans = 1e9;
		if (le >= 0) {
			ans = min(ans, b - a[le]);
		}
		if (ri <= N - k) {
			ans = min(ans, a[ri + k - 1] - b);
		}
		cout << ans << '\n';
	}
}