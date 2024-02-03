#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    bool ok = true;
    if (!isupper(S[0])) {
        ok = false;
    }
    for (char i: S.substr(1)) {
        if (!islower(i)) {
            ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
}