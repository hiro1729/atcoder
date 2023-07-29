#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (char i: s) {
        if (i == '1') c1++;
        if (i == '2') c2++;
        if (i == '3') c3++;
        if (i == '4') c4++;
    }
    cout << max({c1, c2, c3, c4}) << ' ' << min({c1, c2, c3, c4}) << '\n';
}