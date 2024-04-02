#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	string ans;
	bool out = true;
	for (char c: S) {
		if (c == '|') out = !out;
		else if (out) ans += c;
	}
	cout << ans << '\n';
}