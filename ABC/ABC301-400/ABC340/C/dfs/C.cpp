#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> f;

ll dfs(ll x) {
	if (x < 2 || f[x]) return f[x];
	return f[x] = dfs(x / 2) + dfs((x + 1) / 2) + x;
}

int main() {
	ll N;
	cin >> N;
	f[1] = 0;
	cout << dfs(N) << '\n';
}