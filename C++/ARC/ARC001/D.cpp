#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int inf = 1e9;

int main() {
    int n;
    ld s, g;
    cin >> n >> s >> g;
    vector<ld> l(n + 1), r(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    l[n] = g; r[n] = g;
    ld px = s, py = 0;
    ld lx, ly, rx, ry, kl = -inf, kr = inf, ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((l[i] - px) > kl * (i - py)) {
            lx = l[i];
            ly = i;
            kl = (l[i] - px) / (i - py);
        }
        if ((r[i] - px) < kr * (i - py)) {
            rx = r[i];
            ry = i;
            kr = (r[i] - px) / (i - py);
        }
        if (kl > kr) {
            if (ly < ry) {
                ans += hypot(ly - py, lx - px);
                px = lx;
                py = ly;
            }
            if (ly > ry) {
                ans += hypot(ry - py, rx - px);
                px = rx;
                py = ry;
            }
            kl = -inf;
            kr = inf;
            i = py;
        }
    }
    ans += hypot(n - py, l[n] - px);
    cout << fixed << setprecision(12) << ans << '\n';
}