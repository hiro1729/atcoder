#include <bits/stdc++.h>
using namespace std;

int main() {
	int Y;
	cin >> Y;
	if (Y % 4 != 0) {
		cout << 365 << '\n';
	} else if (Y % 100 != 0) {
		cout << 366 << '\n';
	} else if (Y % 400 != 0) {
		cout << 365 << '\n';
	} else {
		cout << 366 << '\n';
	}
}