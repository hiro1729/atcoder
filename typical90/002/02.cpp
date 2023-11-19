#include <bits/stdc++.h>
using namespace std;

bool is_ok(string par) {
	int dep = 0;
	for (char i: par) {
		dep += (i == '(' ? 1 : -1);
		if (dep < 0) {
			return false;
		}
	}
	return dep == 0;
}

int main() {
	int N;
	cin >> N;
	if (N % 2) {
		return 0;
	}
	vector<string> ans;
	for (int i = 0; i < (1 << N); i++) {
		string par;
		for (int j = N - 1; j >= 0; j--) {
			par += "()"[(i >> j) & 1];
		}
		if (is_ok(par)) {
			cout << par << '\n';
		}
	}
}