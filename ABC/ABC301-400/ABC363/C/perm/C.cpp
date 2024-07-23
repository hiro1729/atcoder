#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K; string S;
	cin >> N >> K >> S;
	sort(S.begin(), S.end());
	int ans = 0;
	do {
		bool ok = true;
		for (int i = 0; i < N - K + 1; i++) {
			bool now_ok = true;
			for (int j = 0; j < K / 2; j++) {
				if (S[i + j] != S[i + K - 1 - j]) {
					now_ok = false;
				}
			}
			if (now_ok) {
				ok = false;
			}
		}
		if (ok) {
			ans++;
		}
	} while (next_permutation(S.begin(), S.end()));
	cout << ans << '\n';
}