// O(N)

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        int j = 4 * n - m - 2 * i;
        int k = m - 3 * n + i;
        if (0 <= j && j <= n && 0 <= k && k <= n) {
            cout << i << ' ' << j << ' ' << k << '\n';
            return 0;
        }
    }
    cout << "-1 -1 -1\n";
}
