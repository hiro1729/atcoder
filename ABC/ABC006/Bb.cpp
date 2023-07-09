// 行列累乗による解法 O(log(N))

#include <iostream>
using namespace std;
const int mod = 10007;

struct m3 { int p[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}; };

m3 mul(m3 a, m3 b) {
    m3 c;
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            for (int j = 0; j < 3; j++) {
                c.p[i][j] += a.p[i][k] * b.p[k][j];
                c.p[i][j] %= mod;
            }
        }
    }
    return c;
}

m3 pow(m3 a, int n) {
    m3 q;
    bool f = false;
    for (int i = 0; i < 20; i++) {
        if ((n & (1 << i))) {
            if (f)
                q = mul(q, a);
            else {
                q = a;
                f = true;
            }
        }
        a = mul(a, a);
    }
    return q;
}

int main() {
    int n;
    cin >> n;
    m3 a;
    a.p[0][0] = 1;
    a.p[0][1] = 1;
    a.p[0][2] = 1;
    a.p[1][0] = 1;
    a.p[2][1] = 1;
    if (n < 4) {
        cout << max(0, n - 2) << '\n';
        return 0;
    }
    m3 b = pow(a, n - 3);
    cout << (2 * b.p[2][0] + b.p[2][1] + b.p[2][2]) % mod << '\n';
}
