#include <iostream>
using namespace std;

int f(int x) {
    int ans = (x / 2) * (x / 2 - 1);
    if (x % 2) {
        ans += x / 2;
    }
    return ans;
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    if (r <= 40 && g <= 40 && b <= 40) {
        cout << f(r) + f(g) + f(b);
    }
}
