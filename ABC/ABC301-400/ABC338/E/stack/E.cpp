#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> P(2 * N);
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		A--; B--;
		if (A > B) {
			swap(A, B);
		}
		P[A] = i;
		P[B] = N + i;
	}
	stack<int> s;
	for (int i: P) {
		if (i < N) {
			s.push(i);
		} else {
			if (s.top() != i - N) {
				cout << "Yes\n";
				return 0;
			}
			s.pop();
		}
	}
	cout << "No\n";
}