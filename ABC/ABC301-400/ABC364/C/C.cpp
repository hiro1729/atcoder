#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	ll X, Y;
	cin >> N >> X >> Y;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	ll sA = 0, sB = 0;
	int cA = 0, cB = 0;
	for (int a: A) {
		sA += a;
		cA++;
		if (sA > X) {
			break;
		}
	}
	for (int b: B) {
		sB += b;
		cB++;
		if (sB > Y) {
			break;
		}
	}
	cout << min(cA, cB) << '\n';
}