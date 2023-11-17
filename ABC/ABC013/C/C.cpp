#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll N, H, A, B, C, D, E;
	cin >> N >> H >> A >> B >> C >> D >> E;
	ll ans = 1000000000000000;

	for (ll i = 0; i <= N; i++) {
		// ll x = max(0LL, (E * N - (B + E) * i - H) / (D + E) + 1);
		// この部分で負÷正が発生し、丸めにより x = 0 になるべきところが x = 1 になってしまうことがあります
		ll t = E * N - (B + E) * i - H;
		if (t >= 0) {
			ll x = max(0LL, t / (D + E) + 1);
			if (i + x <= N) {
				ans = min(ans, i * A + x * C);
			}
		} else {
			// ll x = 0;
			ans = min(ans, i * A);
		}
	}
	cout << ans << '\n';
}