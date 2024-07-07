#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, e, f, g, h, i, j, k, l;
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
	auto check = [](int x, int y, int z, int w) {
		return max(x, z) < min(y, w);
	};
	if (check(a, d, g, j) && check(b, e, h, k) && check(c, f, i, l)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}