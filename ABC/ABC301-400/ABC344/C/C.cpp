#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int M;
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	int L;
	cin >> L;
	vector<int> C(L);
	for (int i = 0; i < L; i++) {
		cin >> C[i];
	}
	set<int> s;
	for (int a: A) {
		for (int b: B) {
			for (int c: C) {
				s.insert(a + b + c);
			}
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int X;
		cin >> X;
		cout << (s.find(X) != s.end() ? "Yes" : "No") << '\n';
	}
}