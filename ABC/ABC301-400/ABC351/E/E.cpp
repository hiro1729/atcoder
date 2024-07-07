/*
点を市松に塗ったとき、同じ色の頂点どうししか行き来できないので、色ごとに足す
その色はx座標とy座標の和の偶奇で分けられる
1回のジャンプで移動できる頂点をつなげると斜め45度の格子になるので、色ごとに直交座標に直す
直交座標に直したものでは、最小の移動回数はマンハッタン距離になるので、x座標とy座標で分解して足せる
1次元では、この問題になる: https://atcoder.jp/contests/abc186/tasks/abc186_d
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
	}
	vector<int> evenX, evenY, oddX, oddY;
	for (int i = 0; i < N; i++) {
		if ((X[i] + Y[i]) % 2 == 0) {
			evenX.push_back((X[i] + Y[i]) / 2);
			evenY.push_back((Y[i] - X[i]) / 2);
		} else {
			oddX.push_back((X[i] + Y[i] - 1) / 2);
			oddY.push_back((Y[i] - X[i] - 1) / 2);
		}
	}
	auto calc = [](vector<int> a) {
		sort(a.begin(), a.end());
		int n = a.size();
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (ll)(-n + 1 + 2 * i) * a[i];
		}
		return ans;
	};
	cout << calc(evenX) + calc(evenY) + calc(oddX) + calc(oddY) << '\n';
}