#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i], x[i]--, y[i]--;
    }
    map<tuple<int, int, int, int>, int> m;
    auto f = [&](auto self, int l, int r, int d, int u) -> int {
        if (l >= r || d >= u) return 0;
        if (m.count({l, r, d, u})) return m[{l, r, d, u}];
        int a = 0;
        for (int i = 0; i < n; i++) {
            if (l <= x[i] && x[i] < r && d <= y[i] && y[i] < u) {
                a = max(a, self(self, l, x[i], d, y[i]) + self(self, l, x[i], y[i] + 1, u) + self(self, x[i] + 1, r, d, y[i]) + self(self, x[i] + 1, r, y[i] + 1, u) + r - l + u - d - 1);
            }
        }
        return m[{l, r, d, u}] = a;
    };
    cout << f(f, 0, w, 0, h) << '\n';
}