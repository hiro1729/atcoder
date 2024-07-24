#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	string S;
	cin >> N >> K >> S;
	sort(S.begin(), S.end());
	int ans = 0;
	do {
		string T = ".";
		for (char c: S) {
			T += c;
			T += '.';
		}
		// Manacher's algorithm
		int C = 0, L = 2 * N + 1;
		vector<int> R(L);
		for (int i = 0; i < L; i++) {
			int l = 2 * C - i;
			if (i + R[l] < C + R[C]) {
				R[i] = R[l];
			} else {
				int j = C + R[C] - i;
				while (i >= j && i + j < L && T[i - j] == T[i + j]) {
					j++;
				}
				R[i] = j;
				C = i;
			}
		}
		int m = 0;
		for (int i = K % 2; i < L; i += 2) {
			m = max(m, R[i]);
		}
		if (K + 1 > m) {
			ans++;
		}
	} while (next_permutation(S.begin(), S.end()));
	cout << ans << '\n';
}