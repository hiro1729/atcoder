#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i].first >> m[i].second;
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    int ans = 0;
    do {
        vector<vector<bool>> a(h + 2, vector<bool>(w + 2, true));
        for (int i = 0; i < w + 2; i++) {
            a[0][i] = false;
            a[h + 1][i] = false;
        }
        for (int i = 0; i < h + 2; i++) {
            a[i][0] = false;
            a[i][w + 1] = false;
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            int x = m[p[i]].first, y = m[p[i]].second;
            a[x][y] = false; c++;
            for (int d = 0; d < 4; d++) {
                int nx = x, ny = y;
                while (a[nx += dx[d]][ny += dy[d]]) {
                    a[nx][ny] = false;
                    c++;
                }
            }
        }
        ans = max(ans, c);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
}