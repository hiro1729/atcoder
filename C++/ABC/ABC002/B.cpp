#include <iostream>
using namespace std;

int main() {
    string w;
    cin >> w;
    for (char i: w) {
        if (i != 'a' && i != 'i' && i != 'u' && i != 'e' && i != 'o') {
            cout << i;
        }
    }
    cout << '\n';
}
