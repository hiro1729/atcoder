#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
	string T;
	cin >> T;
	int N;
	cin >> N;
	vector<int> dp(T.size() + 1, inf);
	dp[0] = 0;
	while (N--) {
		vector<int> ndp = dp;
		int A;
		cin >> A;
		while (A--) {
			string S;
			cin >> S;
			for (int i = 0; i <= T.size(); i++) {
				if (i + S.size() <= T.size() && T.substr(i, S.size()) == S) {
					ndp[i + S.size()] = min(ndp[i + S.size()], dp[i] + 1);
				}
			}
		}
		dp = ndp;
	}
	cout << (dp[T.size()] >= inf ? -1 : dp[T.size()]) << '\n';
}