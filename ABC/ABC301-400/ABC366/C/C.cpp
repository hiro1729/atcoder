#include <bits/stdc++.h>
using namespace std;

int main() {
	int Q; cin >> Q;
	map<int, int> m;
	while (Q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x; cin >> x;
			m[x]++;
		} else if (t == 2) {
			int x;
			cin >> x;
			m[x]--;
			if (m[x] == 0) m.erase(x);
		} else {
			cout << m.size() << '\n';
		}
	}
}