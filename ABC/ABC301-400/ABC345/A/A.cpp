#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	if (S[0] != '<' || S.back() != '>') {
		cout << "No\n";
		return 0;
	}
	for (int i = 1; i < S.size() - 1; i++) {
		if (S[i] != '=') {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}