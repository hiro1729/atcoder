#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> P(N), Prev(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		Prev[P[i] - 1] = i;
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int A, B;
		cin >> A >> B;
		cout << (Prev[A - 1] < Prev[B - 1] ? A : B) << '\n';
	}
}