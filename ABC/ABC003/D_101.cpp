#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
ll d, l;
vector<vector<ll>> C;
 
void pascal_init(int n) {
    C.resize(n + 1, vector<ll>(n + 1));
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

ll t(ll x, ll y) {
    if (x * y < l + d || x <= 0 || y <= 0) return 0;
    return C[x * y][l + d] * C[l + d][l] % mod;
}

int main() {
    ll r, c, x, y;
    pascal_init(900);
    cin >> r >> c >> x >> y >> d >> l;
    ll ans = (t(x, y) - t(x - 1, y) * 2 - t(x, y - 1) * 2 + t(x - 2, y) + t(x, y - 2) + t(x - 1, y - 1) * 4 - t(x - 2, y - 1) * 2 - t(x - 1, y - 2) * 2 + t(x - 2, y - 2)) % mod;
    cout << (ans * (r - x + 1) * (c - y + 1) % mod + mod) % mod << '\n';
}
