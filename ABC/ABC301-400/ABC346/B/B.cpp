#include <bits/stdc++.h>
using namespace std;

int main() {
	string S = "wbwbwwbwbwbw";
	for (int i = 0; i < 5; i++) S += S;
	int W, B;
	cin >> W >> B;
	for (int i = 0; i < 100; i++) {
		if (count(S.begin() + i, S.begin() + i + W + B, 'w') == W) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}