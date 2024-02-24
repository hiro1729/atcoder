#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	vector<int> cnt(26);
	for (char c: S) {
		cnt[c - 'a']++;
	}
	int d = find(cnt.begin(), cnt.end(), 1) - cnt.begin();
	cout << find(S.begin(), S.end(), 'a' + d) - S.begin() + 1 << '\n';
}