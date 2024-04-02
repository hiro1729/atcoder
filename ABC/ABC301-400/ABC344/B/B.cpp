#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> A;
	while (true) {
		int a;
		cin >> a;
		A.push_back(a);
		if (a == 0) break;
	}
	reverse(A.begin(), A.end());
	for (int i: A) {
		cout << i << '\n';
	}
}