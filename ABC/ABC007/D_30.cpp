#include <bits/stdc++.h>
using namespace std;

bool ok(int n) {
    while (n) {
        if (n % 10 == 4 || n % 10 == 9) return true;
        n /= 10;
    }
    return false;
}

int main() {
    int a, b;
    cin >> a >> b;
    if (b <= 10000) {
        int ans = 0;
        for (int i = a; i <= b; i++) ans += ok(i);
        cout << ans << '\n';
    }
}
