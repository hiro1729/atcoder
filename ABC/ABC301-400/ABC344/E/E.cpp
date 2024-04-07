#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000001;

int main() {
	int N;
	cin >> N;
	vector<int> A(N + 2);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	A[N + 1] = inf;
	map<int, int> next, prev;
	for (int i = 0; i < N + 1; i++) {
		next[A[i]] = A[i + 1];
		prev[A[i + 1]] = A[i];
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			next[y] = next[x];
			prev[next[x]] = y;
			next[x] = y;
			prev[y] = x;
		} else {
			int x;
			cin >> x;
			next[prev[x]] = next[x];
			prev[next[x]] = prev[x];
		}
	}
	int now = next[0];
	while (now != inf) {
		cout << now << ' ';
		now = next[now];
	}
}