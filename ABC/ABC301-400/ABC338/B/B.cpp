#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	vector<int> cnt(26);
	for (char c: S) {
		cnt[c - 'a']++;
	}
	int mx = *max_element(cnt.begin(), cnt.end());
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == mx) {
			cout << char('a' + i) << '\n';
			return 0;
		}
	}
}