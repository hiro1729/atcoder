// O(N^2)

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n <= 1500 && m <= 7500) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                int k = n - i - j;
                if (k >= 0 && 2 * i + 3 * j + 4 * k == m) {
                    cout << i << ' ' << j << ' ' << k << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1\n";
}
