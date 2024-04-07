#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N - 2; i++) {
		cout << A[i] * A[i + 1] << ' ';
	}
	cout << A[N - 2] * A[N - 1] << '\n';
}