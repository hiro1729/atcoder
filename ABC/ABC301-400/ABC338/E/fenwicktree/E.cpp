#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> P(N);
	fenwick_tree<int> fwA(2 * N), fwB(2 * N);
	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
		P[i].first--;
		P[i].second--;
		if (P[i].first > P[i].second) {
			swap(P[i].first, P[i].second);
		}
		fwA.add(P[i].first, 1);
		fwB.add(P[i].second, 1);
	}
	for (auto [A, B]: P) {
		if (fwB.sum(A + 1, B) < fwA.sum(A + 1, B)) {
			cout << "Yes\n";
			return 0;
		}
		fwA.add(A, -1);
		fwB.add(B, -1);
	}
	cout << "No\n";
}