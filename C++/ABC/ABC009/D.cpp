#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll k, m;
    cin >> k >> m;
    vector<ll> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    vector<vector<ll>> c(k, vector<ll>(k)), x(k, vector<ll>(k));
    for (int i = 0; i < k; i++) {
        cin >> c[0][i];
    }
    for (int i = 0; i < k - 1; i++) {
        c[i + 1][i]--;
    }
    for (int i = 0; i < k; i++) {
        x[i][i]--;
    }
    auto mul = [&](vector<vector<ll>> &a, vector<vector<ll>> b) {
        vector<vector<ll>> t(k, vector<int>(k));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                for (int s = 0; s < k; s++) {
                    t[i][j] ^= a[i][s] & b[s][j];
                }
           }
        }
        a = t;
    };
    for (m--; m; m /= 2) {
        if (m % 2) mul(x, c);
        mul(c, c);
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans ^= x[k - 1][i] & a[k - i - 1];
    }
    cout << ans << '\n';
}
