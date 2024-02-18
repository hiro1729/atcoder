#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int S, T;
		cin >> S >> T;
		A[i + 1] += A[i] / S * T;
		A[i] %= S;
	}
	cout << A[N - 1] << '\n';
}