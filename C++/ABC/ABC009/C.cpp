#include <iostream>
using namespace std;

int main() {
    int n, k;
    string s, t, u;
    cin >> n >> k >> s;
    t = s;
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = i + 1; j < n; j++) {
            if (t[x] > t[j]) {
                u = t;
                swap(u[i], u[j]);
                int c = 0;
                for (int l = 0; l < n; l++) {
                    if (s[l] != u[l]) c++;
                }
                if (c <= k) {
                    x = j;
                }
            }
        }
        swap(t[i], t[x]);
    }
    cout << t << '\n';
}
