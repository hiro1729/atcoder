#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	fenwick_tree<int> fwA(2 * N), fwB(2 * N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		if (A[i] > B[i]) {
			swap(A[i], B[i]);
		}
		fwA.add(A[i], 1);
		fwB.add(B[i], 1);
	}
	for (int i = 0; i < N; i++) {
		if (fwB.sum(A[i] + 1, B[i]) < fwA.sum(A[i] + 1, B[i])) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}