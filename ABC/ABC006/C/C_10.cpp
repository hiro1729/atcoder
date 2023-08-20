// O(N^3)

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n <= 100 && m <= 500) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n; k++) {
                    if (i + j + k == n && 2 * i + 3 * j + 4 * k == m) {
                        cout << i << ' ' << j << ' ' << k << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "-1 -1 -1\n";
}
