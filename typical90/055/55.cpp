#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                for (int l = 0; l < k; l++) {
                    for (int m = 0; m < l; m++) {
                        if (a[i] * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q) ans++;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}