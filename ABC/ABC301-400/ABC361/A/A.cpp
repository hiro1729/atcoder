#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K, X;
	cin >> N >> K >> X;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	A.insert(A.begin() + K, X);
	for (int i = 0; i < N + 1; i++) {
		cout << A[i] << ' ';
	}
	cout << '\n';
}