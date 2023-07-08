#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    xb -= xa;
    yb -= ya;
    xc -= xa;
    yc -= ya;
    long double a = (xb * yc - xc * yb) / 2.0;
    cout << fixed << setprecision(5) << max(a, -a) << '\n';
}
