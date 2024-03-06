#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> ans;
		for (int j = 0; j < N; j++) {
			cin >> A;
			if (A == 1) {
				ans.push_back(j + 1);
			}
		}
		if (ans.size() > 0) {
			for (int j = 0; j < ans.size() - 1; j++) {
				cout << ans[j] << ' ';
			}
			cout << ans[ans.size() - 1];
		}
		cout << '\n';
	}
}