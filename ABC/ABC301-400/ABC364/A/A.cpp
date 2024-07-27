#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < N - 2; i++) {
		if (S[i] == "sweet" && S[i + 1] == "sweet") {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}