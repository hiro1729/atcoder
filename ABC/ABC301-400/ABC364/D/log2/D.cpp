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
		int le = -1, ri = 200000000;
		while (le + 1 < ri) {
			int mi = (le + ri) / 2;
			if (lower_bound(a.begin(), a.end(), b + mi + 1) - lower_bound(a.begin(), a.end(), b - mi) >= k) {
				ri = mi;
			} else {
				le = mi;
			}
		}
		cout << ri << '\n';
	}
}