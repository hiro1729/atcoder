#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N), cntA(2 * N), cntB(2 * N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		if (A[i] > B[i]) {
			swap(A[i], B[i]);
		}
		cntA[A[i]]++;
		cntB[B[i]]++;
	}
	for (int i = 1; i < 2 * N; i++) {
		cntA[i] += cntA[i - 1];
		cntB[i] += cntB[i - 1];
	}
	for (int i = 0; i < N; i++) {
		if (cntB[B[i] - 1] - cntB[A[i]] < cntA[B[i] - 1] - cntA[A[i]]) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}