// 満点解法 累積和 前計算O(N^2) クエリあたりO(N^4) → O(N^2+N^4・Q)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, p;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    int dac[51][51];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dac[i + 1][j + 1] = dac[i + 1][j] + d[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            dac[i + 1][j] += dac[i][j];
        }
    }
    cin >> q;
    while (cin >> p) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i * j > p)
                    break;
                int now = 0;
                for (int s = 0; s <= n - i; s++) {
                    for (int t = 0; t <= n - j; t++) {
                        now = max(now, dac[s][t] + dac[s + i][t + j] - dac[s][t + j] - dac[s + i][t]);
                    }
                }
                ans = max(ans, now);
            }
        }
        cout << ans << '\n';
    }
}
