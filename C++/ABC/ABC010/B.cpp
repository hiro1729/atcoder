#include <iostream>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    int ans = 0;
    int d[] = {0, 0, 1, 0, 1, 2, 3, 0, 1, 0};
    while (cin >> a) {
        ans += d[a];
    }
    cout << ans << '\n';
}