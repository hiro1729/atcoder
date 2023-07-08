#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    bool ans = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[i]) continue;
        if (s[i] == '@') {
            if (t[i] == 'a' || t[i] == 't' || t[i] == 'c' || t[i] == 'o' || t[i] == 'd' || t[i] == 'e' || t[i] == 'r') continue;
            ans = false;
            break;
        }
        if (t[i] == '@') {
            if (s[i] == 'a' || s[i] == 't' || s[i] == 'c' || s[i] == 'o' || s[i] == 'd' || s[i] == 'e' || s[i] == 'r') continue;
            ans = false;
            break;
        }
        ans = false;
    }
    cout << "You " << (ans ? "can win\n" : "will lose\n");
}
