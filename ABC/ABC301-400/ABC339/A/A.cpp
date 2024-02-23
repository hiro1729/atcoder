#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	cout << S.substr(S.rfind('.') + 1) << '\n';
}