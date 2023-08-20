// DP O(N^2)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m = 0;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    if (n <= 1000) {
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < n; j++) {
                if (c[i] <= c[j]) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            m = max(m, dp[i]);
        }
        cout << n - m << '\n';
    }
}
