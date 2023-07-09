// 部分点50点解法 全探索O(N^6・Q) (Q=N^2としてO(N^8))

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, p;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> d[i][j];
    }
    cin >> q;
    while (cin >> p) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i * j > p) break;
                for (int s = 0; s <= n - i; s++) {
                    for (int t = 0; t <= n - j; t++) {
                        int now = 0;
                        for (int k = 0; k < i; k++) {
                            for (int l = 0; l < j; l++) {
                                now += d[s + k][t + l];
                            }
                        }
                        ans = max(ans, now);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
