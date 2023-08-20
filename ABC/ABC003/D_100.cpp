#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

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

int main() {
    pascal_init(900);
    int r, c, x, y, d, l;
    cin >> r >> c >> x >> y >> d >> l;
    if (d + l == x * y) {
        cout << C[d + l][d] * (r - x + 1) * (c - y + 1) % mod << '\n';
    }
}
