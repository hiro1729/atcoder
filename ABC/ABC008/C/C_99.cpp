#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i;
    int s = 0, cn = 0;
    do {
        cn++;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                b[j] += (c[p[j]] % c[p[i]] == 0);
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] % 2 == 0) {
                s++;
            }
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << fixed << setprecision(10) << (double)s / cn << '\n';
}