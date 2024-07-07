/*
Aを座標圧縮し、Aに含まれるiごとに、iの個数とiの和をBITに乗せる
すると、i以下の個数と和を求めることができる
*/

#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	set<int> st;
	for (int i: A) {
		st.insert(i);
	}
	int L = st.size(), c = 0;
	map<int, int> mp;
	for (int i: st) {
		mp[i] = c++;
	}
	fenwick_tree<ll> cnt(L), sum(L);
	ll ans = 0;
	for (int i: A) {
		int d = mp[i];
		ans += cnt.sum(0, d) * i - sum.sum(0, d);
		cnt.add(d, 1);
		sum.add(d, i);
	}
	cout << ans << '\n';
}