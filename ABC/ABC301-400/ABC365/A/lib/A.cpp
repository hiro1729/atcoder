#include <bits/stdc++.h>
using namespace std;

int main() {
	int Y;
	cin >> Y;
	if (chrono::year{Y}.is_leap()) {
		cout << 366 << '\n';
	} else {
		cout << 365 << '\n';
	}
}