// O(1)

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m % 2) {
        int a = 2 * n - m / 2 - 1;
        int c = m / 2 - n;
        if (a >= 0 && c >= 0) {
            cout << a << " 1 " << c << '\n';
        } else {
            cout << "-1 -1 -1\n";
        }
    } else {
        int a = 2 * n - m / 2;
        int c = m / 2 - n;
        if (a >= 0 && c >= 0) {
            cout << a << " 0 " << c << '\n';
        } else {
            cout << "-1 -1 -1\n";
        }
    }
}
