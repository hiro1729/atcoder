# ABC002 D - 派閥 解説

## 問題概要

$N$人の国会議員と$M$個の人間関係$(x, y)$が与えられる。ここから数人を選んで派閥を作るが、全員が互いに知り合いでなければならない。このとき、派閥の最大人数を求める。

## 制約

$$ 1 \leqq N \leqq 12
0 \leqq M \leqq \frac{N(N-1)}{2} $$

## 制約からの考察

$N$の上限が小さいので、$O(2^n)$周辺のアルゴリズム、bit全探索が思いつく。

## 考察

一つの派閥に属する国会議員をbit全探索できる。国会議員を全探索したときに、互いの関係が存在するかどうかを判定し、存在しなければその派閥を作ることはできない。

## コード

``` cpp
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
```

``` py
n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    g[x].append(y)
    g[y].append(x)
ans = 0
for i in range(1 << n):
    a = [j for j in range(n) if i & (1 << j)]
    ok = True
    for j in a:
        for k in a:
            if j != k:
                if j not in g[k]:
                    ok = False
    if ok:
        ans = max(ans, len(a))
print(ans)
```