#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	int N = stoi(S.substr(3));
	if (0 < N && N <= 349 && N != 316) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}