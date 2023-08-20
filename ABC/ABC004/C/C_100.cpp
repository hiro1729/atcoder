#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < n % 30; i++) {
        swap(a[i % 5], a[i % 5 + 1]);
    }
    for (int i = 0; i < 6; i++) {
        cout << a[i];
    }
    cout << '\n';
}
