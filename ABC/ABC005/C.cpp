#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n, m, b;
    cin >> t >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 0;
    cin >> m;
    while (cin >> b) {
        while (r < n && a[r] <= b) r++;
        while (l < n && a[l] + t < b) l++;
        if (l == r) {
            cout << "no\n";
            return 0;
        }
        l++;
    }
    cout << "yes\n";
}
