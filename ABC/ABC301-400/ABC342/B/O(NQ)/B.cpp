#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int A, B;
		cin >> A >> B;
		cout << (find(P.begin(), P.end(), A) - P.begin() < find(P.begin(), P.end(), B) - P.begin() ? A : B) << '\n';
	}
}