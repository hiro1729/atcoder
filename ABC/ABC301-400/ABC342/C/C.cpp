#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, Q;
	string S;
	cin >> N >> S >> Q;
	vector<int> chars(26);
	iota(chars.begin(), chars.end(), 0);
	for (int i = 0; i < Q; i++) {
		char c, d;
		cin >> c >> d;
		for (int j = 0; j < 26; j++) {
			if (chars[j] == c - 'a') {
				chars[j] = d - 'a';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << char(chars[S[i] - 'a'] + 'a');
	}
}