#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> B = A;
	sort(B.rbegin(), B.rend());
	cout << find(A.begin(), A.end(), B[1]) - A.begin() + 1 << '\n';
}