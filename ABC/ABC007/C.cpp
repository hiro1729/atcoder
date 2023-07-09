#include <bits/stdc++.h>
using namespace std;

vector<int> dxs = {1, 0, -1, 0};
vector<int> dys = {0, 1, 0, -1};

int main() {
    int h, w, x0, y0, x1, y1;
    cin >> h >> w >> x0 >> y0 >> x1 >> y1;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> que;
    dist[x0 - 1][y0 - 1] = 0;
    que.push(make_pair(x0 - 1, y0 - 1));
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dxs[dir];
            int ny = y + dys[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (s[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            que.push(make_pair(nx, ny));
        }
    }
    cout << dist[x1 - 1][y1 - 1] << '\n';
}
