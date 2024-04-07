#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	set<int> s;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		s.insert(A);
	}
	long long ans = (long long)K * (K + 1) / 2;
	for (int i: s) {
		if (i <= K) ans -= i;
	}
	cout << ans << '\n';
}