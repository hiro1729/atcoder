#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> A(9), B(8);
	int Asum = 0, Bsum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> A[i];
		Asum += A[i];
	}
	for (int i = 0; i < 8; i++) {
		cin >> B[i];
		Bsum += B[i];
	}
	cout << Asum - Bsum + 1 << '\n';
}