#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    rep(i, n) rep(j, i) rep(k, j) rep(l, k) rep(m, l) {
        if (a[i] * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q) ans++;
    }
    cout << ans << '\n';
}