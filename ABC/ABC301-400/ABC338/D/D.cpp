#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> X(M);
	for (int i = 0; i < M; i++) {
		cin >> X[i];
		X[i]--;
	}
	ll s = 0;
	vector<ll> ac(N + 1);
	for (int i = 0; i < M - 1; i++) {
		int k = abs(X[i + 1] - X[i]);
		s += min(k, N - k);
		if (k <= N / 2) {
			ac[min(X[i], X[i + 1])] += N - k * 2;
			ac[max(X[i], X[i + 1])] -= N - k * 2;
		} else {
			ac[0] += 2 * k - N;
			ac[min(X[i], X[i + 1])] -= 2 * k - N;
			ac[max(X[i], X[i + 1])] += 2 * k - N;
			ac[N] -= 2 * k - N;
		}
	}
	for (int i = 0; i < N; i++) {
		ac[i + 1] += ac[i];
	}
	cout << s + *min_element(ac.begin(), ac.end()-1) << '\n';
}