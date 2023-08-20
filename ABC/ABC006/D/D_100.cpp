// O(Nlog(N))

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m = 1;
    cin >> n;
    vector<int> c(n), l(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    l[0] = c[0];
    for (int i = 1; i < n; i++) {
        if (l[m - 1] < c[i]) {
            l[m++] = c[i];
        } else {
            *lower_bound(l.begin(), l.begin() + m, c[i]) = c[i];
        }
    }
    cout << n - m << '\n';
}
