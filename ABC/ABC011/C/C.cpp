#include <iostream>
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	if (n == a || n == b || n == c) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < 100; i++) {
		int k = 0;
		for (int j = 1; j < 4; j++) {
			if (n >= j && n - j != a && n - j != b && n - j != c) k = j;
		}
		n -= k;
		if (n == 0) break;
	}
	cout << (n == 0 ? "YES\n" : "NO\n");
}