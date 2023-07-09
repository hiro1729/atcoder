#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll x) {
    if (x == 0) return 0;
    vector<ll> d;
    while (x) {
        d.push_back(x % 10);
        x /= 10;
    }
    reverse(d.begin(), d.end());
    vector<vector<ll>> dp1(2, vector<ll>(2, 0)), dp2(2, vector<ll>(2, 0));
    dp1[0][0] = 1;
    for (auto c: d) {
        dp2[0][0] = (c != 4 && c != 9) * dp1[0][0];
        dp2[0][1] = (c == 4 || c == 9) * dp1[0][0] + dp1[0][1];
        dp2[1][0] = (c - (c > 4)) * dp1[0][0] + 8ll * dp1[1][0];
        dp2[1][1] = (c > 4) * dp1[0][0] + c * dp1[0][1] + 2ll * dp1[1][0] + 10ll * dp1[1][1];
        dp1 = dp2;
    }
    return dp1[0][1] + dp1[1][1];
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << solve(b) - solve(a - 1) << '\n';
}
