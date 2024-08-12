#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	vector<int> len(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		len[i] = S[i].size();
	}
	int L = *max_element(len.begin(), len.end());
	for (int i = 0; i < L; i++) {
		string ans = "";
		for (int j = N - 1; j >= 0; j--) {
			ans += (i < len[j] ? S[j][i] : '*');
		}
		while (ans.back() == '*') {
			ans.pop_back();
		}
		cout << ans << '\n';
	}
}