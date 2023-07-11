#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    if (m < 100) {
        cout << "00\n";
    } else if (m <= 5000) {
        if (m < 1000) {
            cout << "0";
        }
        cout << m / 100 << '\n';
    } else if (m <= 30000) {
        cout << m / 1000 + 50 << '\n';
    } else if (m <= 70000) {
        cout << (m / 1000 - 30) / 5 + 80 << '\n';
    } else {
        cout << "89\n";
    }
}
