#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
ll h, w, x, y, d, l, ans;

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
  pascal_init(900);
  cin >> x >> y >> h >> w >> d >> l;
  ans = (t(h, w) - t(h - 1, w) * 2 - t(h, w - 1) * 2 + t(h - 2, w) + t(h, w - 2) + t(h - 1, w - 1) * 4 - t(h - 2, w - 1) * 2 - t(h - 1, w - 2) * 2 + t(h - 2, w - 2)) % mod;
  cout << (ans * (x - h + 1) * (y - w + 1) % mod + mod) % mod << '\n';
}
