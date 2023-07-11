#include <iostream>
using namespace std;

int main() {
    int n, x, ans = 100;
    cin >> n;
    while (cin >> x) ans = min(ans, x);
    cout << ans << '\n';
}
