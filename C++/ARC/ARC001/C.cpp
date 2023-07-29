#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<string> b(8);
    for (int i = 0; i < 8; i++) {
        cin >> b[i];
    }
    do {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            if (b[i][a[i]] == 'Q') cnt++;
        }
        if (cnt != 3) {
            continue;
        }
        bool f = true;
        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 8; j++) {
                if (abs(i - j) == abs(a[i] - a[j])) {
                    f = false;
                }
            }
        }
        if (f) {
            for (int i = 0; i < 8; i++) {
                b[i][a[i]] = 'Q';
                cout << b[i] << '\n';
            }
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << "No Answer\n";
}