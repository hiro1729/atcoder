#include <iostream>
#include <cmath>
using namespace std;

long double f(int x, int y, int tx, int ty) {
    return sqrt((long double)((x - tx) * (x - tx) + (y - ty) * (y - ty)));
}

int main() {
    int txa, tya, txb, tyb, t, v, n, x, y;
    cin >> txa >> tya >> txb >> tyb >> t >> v >> n;
    while (cin >> x >> y) {
        long double d = f(x, y, txa, tya) + f(x, y, txb, tyb);
        if ((t * v - d) >= -1e-8) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
