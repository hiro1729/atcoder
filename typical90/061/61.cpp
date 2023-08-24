#include <iostream>
using namespace std;

int c[300030];
int l = 100010, r = 100010;

int main() {
	int q, t, x;
	cin >> q;
	while (cin >> t >> x) {
		if (t == 1) c[--l] = x;
		if (t == 2) c[r++] = x;
		if (t == 3) cout << c[l + x - 1] << '\n';
	}
}