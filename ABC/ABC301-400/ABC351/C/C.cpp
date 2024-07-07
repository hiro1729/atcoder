#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> B;
	for (int i: A) {
		while (B.size() >= 1 && B.back() == i) {
			B.pop_back();
			i++;
		}
		B.push_back(i);
	}
	cout << B.size() << '\n';
}