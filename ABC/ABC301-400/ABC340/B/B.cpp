#include <bits/stdc++.h>
using namespace std;

int main() {
	int Q;
	cin >> Q;
	vector<int> A;
	while (Q--) {
		int c, x;
		cin >> c >> x;
		if (c == 1) {
			A.push_back(x);
		} else {
			cout << A[A.size() - x] << '\n';
		}
	}
}