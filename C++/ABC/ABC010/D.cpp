#include <iostream>
#include <atcoder/maxflow>
using namespace std;

int main(){
    int n, k, m, u, v;
    cin >> n >> k >> m;
    atcoder::mf_graph<int> g(n + 1);
    while (k--) {
        cin >> u;
        g.add_edge(u, n, 1);
    }
    while (cin >> u >> v) {
        g.add_edge(u, v, 1);
        g.add_edge(v, u, 1);
    }
    cout << g.flow(0, n) << '\n';
}