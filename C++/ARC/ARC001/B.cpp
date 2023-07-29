#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a = abs(a - b);
    int t = 0;
    while (a >= 8) {
        a = abs(a - 10), t++;
    }
    cout << t + min(a, abs(5 - a) + 1) << '\n';
}