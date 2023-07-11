#include <iostream>
using namespace std;

int f(int a, int b) {
    b += a;
    if (a > -1) return (b + a - 1) * (b - a) / 2;
    if (b < 2) return (a - b) * (a + b - 1) / 2;
    return a * (a - 1) / 2 + (b - 1) * b / 2;
}

int main() {
    int r, g, b, d = 1000000;
    cin >> r >> g >> b;
    for (int i = -300; i < 301; i++) d = min(d, f(min(i - r, -100 - r / 2) + 100, r) + f(i, g) + f(max(i + g, 100 - b / 2) - 100, b));
    cout << d << '\n';
}
