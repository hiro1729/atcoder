#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N), cnt(2 * N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		if (A[i] > B[i]) {
			swap(A[i], B[i]);
		}
		cnt[A[i]]++;
		cnt[B[i]]--;
	}
	for (int i = 1; i < 2 * N; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = 0; i < N; i++) {
		if (cnt[A[i]] < cnt[B[i] - 1]) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}