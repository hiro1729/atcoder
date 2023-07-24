// bit全探索 O(N・2^N)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = n;
    if (n <= 16) {
        for (int i = 0; i < (1 << n); i++) {
            int c = 0;
            vector<int> b;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    b.push_back(a[j]);
                    c++;
                }
            }
            bool ok = true;
            for (int i = 0; i < c - 1; i++) {
                if (b[i] > b[i + 1]) ok = false;
            }
            if (ok) {
                ans = min(ans, n - c);
            }
        }
        cout << ans << '\n';
    }
}
