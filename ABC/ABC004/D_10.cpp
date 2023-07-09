#include <iostream>
using namespace std;

int f(int x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    if (x == 3) return 2;
    if (x == 4) return 4;
    if (x == 5) return 6;
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    if (r <= 5 && g <= 5 && b <= 5) {
        cout << f(r) + f(g) + f(b);
    }
}
