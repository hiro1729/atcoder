#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> c(1000001);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		c[a]++;
		if (b < 1000000) {
			c[b + 1]--;
		}
	}
	for (int i = 0; i < 1000000; i++) {
		c[i + 1] += c[i];
	}
	int ans = 0;
	for (int i = 0; i <= 1000000; i++) {
		ans = max(ans, c[i]);
	}
	cout << ans << '\n';
}