#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    map<string, int> m;
    while (n--) {
        cin >> s;
        m[s]++;
    }
    vector<pair<int, string>> p;
    for (auto [i, j]: m) {
        p.push_back({j, i});
    }
    sort(p.begin(), p.end());
    cout << p.back().second << '\n';
}