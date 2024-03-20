#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	map<int, int> m;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int x = A[i];
		for (int j = 447; j > 0; j--) {
			if (x % (j * j) == 0) {
				x /= j * j;
				break;
			}
		}
		if (A[i] == 0) {
			ans += i;
			m[0]++;
		} else {
			ans += m[x] + m[0];
			m[x]++;
		}
	}
	cout << ans << '\n';
}