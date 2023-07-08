#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> r(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        r[x][y] = true;
        r[y][x] = true;
    }
    int ans = 0;
    for (int b = 0; b < (1 << n); b++) {
        vector<int> t;
        for (int i = 0; i < n; i++) {
            if ((b >> i) & 1) t.push_back(i);
        }
        bool f = true;
        for (int a: t) {
            for (int b: t) {
	            if (a == b) continue;
	            f &= r[a][b];
            }
        }
        if (f) {
            ans = max(ans, (int)t.size());
        }
    }
    cout << ans << '\n';
}
