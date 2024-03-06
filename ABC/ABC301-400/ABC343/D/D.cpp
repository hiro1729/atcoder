#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, T, A, B, ans = 1;
	cin >> N >> T;
	vector<ll> score(N);
	map<ll, int> scores;
	scores[0] += N;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		A--;
		scores[score[A]]--;
		if (scores[score[A]] == 0) {
			ans--;
		}
		score[A] += B;
		if (scores[score[A]] == 0) {
			ans++;
		}
		scores[score[A]]++;
		cout << ans << '\n';
	}
}