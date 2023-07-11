#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool rain[289];
    for (int i = 0; i < 289; i++) {
        rain[i] = false;
    }
    string se;
    for (int i = 0; i < n; i++) {
        cin >> se;
        int s_h = stoi(se.substr(0, 2));
        int s_m = stoi(se.substr(2, 2));
        int e_h = stoi(se.substr(5, 2));
        int e_m = stoi(se.substr(7, 2));
        int s_m_rnd = (s_m / 5) * 5;
        int e_m_rnd = 0;
        if (e_m != 0) {
            e_m_rnd = ((e_m - 1) / 5 + 1) * 5;
        }
        int sum_s_m = s_h * 60 + s_m_rnd;
        int sum_e_m = e_h * 60 + e_m_rnd;
        for (int j = sum_s_m / 5; j < sum_e_m / 5; j++) {
            rain[j] = true;
        }
    }
    int now = false;
    for (int i = 0; i < 289; i++) {
        if (rain[i]) {
            if (!now) {
              	now = true;
	              int h = i / 12;
	              int m = i % 12 * 5;
	              if (h < 10) {
                    cout << "0";
                }
                cout << h;
                if (m < 10) {
                    cout << "0";
                }
                cout << m << "-";
            }
        } else {
            if (now) {
                now = false;
                int h = i / 12;
                int m = i % 12 * 5;
                if (h < 10) {
                    cout << "0";
                }
                cout << h;
                if (m < 10) {
                    cout << "0";
                }
                cout << m << endl;
            }
        }
        if (i == 288 && now == true) {
            cout << "2400\n";
        }
    }
}
