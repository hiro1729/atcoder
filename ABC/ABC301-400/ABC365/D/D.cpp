#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	int r = 0, s = 0, p = 0;
	for (char c: S) {
		tie(r, s, p) = make_tuple(max(s, p), max(p, r), max(r, s));
		if (c == 'R') {
			s = 0;
			p++;
		}
		if (c == 'S') {
			p = 0;
			r++;
		}
		if (c == 'P') {
			r = 0;
			s++;
		}
	}
	cout << ranges::max({r, s, p}) << '\n';
}