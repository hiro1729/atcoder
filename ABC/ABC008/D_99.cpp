#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res |= (1 << i);
    }
    auto dfs = [&](auto self, int m, int a, int b, int c, int d) -> int {
        if (!m) return 0;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if ((m >> i) & 1) v.push_back(i);
        }
        int res = 0;
        for (auto i: v) {
            int p = 0, q = 0, r = 0, s = 0;
            for (auto j: v) {
                if (x[j] < x[i] && y[j] < y[i]) p |= (1 << j);
                if (x[j] < x[i] && y[j] > y[i]) q |= (1 << j);
                if (x[j] > x[i] && y[j] < y[i]) r |= (1 << j);
                if (x[j] > x[i] && y[j] > y[i]) s |= (1 << j);
            }
            int cr = c - a + d - b + 1;
            cr += self(self, p, a, b, x[i] - 1, y[i] - 1);
            cr += self(self, q, a, y[i] + 1, x[i] - 1, d);
            cr += self(self, r, x[i] + 1, b, c, y[i] - 1);
            cr += self(self, s, x[i] + 1, y[i] + 1, c, d);
            res = max(res, cr);
        }
        return res;
    };
    cout << dfs(dfs, res, 1, 1, w, h) << '\n';
}