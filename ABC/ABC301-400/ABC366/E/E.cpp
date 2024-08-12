#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, D;
	cin >> N >> D;
	vector<int> x(N), y(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	const int M = 2000001;
	vector<int> ca(D + 1);
	int j = 0;
	ll ns = accumulate(x.begin(), x.end(), 0LL) + (ll)N * M;
	for (int i = -M; i <= M; i++) {
		while (j < N && x[j] <= i) {
			j++;
		}
		ns += 2 * j - N;
		if (ns <= D) {
			ca[ns]++;
		}
	}
	for (int i = 0; i < D; i++) {
		ca[i + 1] += ca[i];
	}

	j = 0;
	ns = accumulate(y.begin(), y.end(), 0LL) + (ll)N * M;
	ll ans = 0;
	for (int i = -M; i <= M; i++) {
		while (j < N && y[j] <= i) {
			j++;
		}
		ns += 2 * j - N;
		if (ns <= D) {
			ans += ca[D - ns];
		}
	}
	cout << ans << '\n';
}