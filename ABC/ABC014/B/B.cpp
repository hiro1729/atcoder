#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, X;
	cin >> n >> X;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (X & (1 << i)) {
			ans += A[i];
		}
	}
	cout << ans << '\n';
}