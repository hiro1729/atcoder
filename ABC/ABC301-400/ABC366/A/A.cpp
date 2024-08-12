#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, T, A;
	cin >> N >> T >> A;
	cout << (T > N / 2 || A > N / 2 ? "Yes" : "No") << '\n';
}