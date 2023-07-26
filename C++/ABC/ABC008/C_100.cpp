#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double a = 0;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (c[i] % c[j] == 0) {
                k++;
            }
        }
        a += (k % 2 ? (k + 1.0) / 2 / k : 0.5);
    }
    cout << fixed << setprecision(10) << a << '\n';
}