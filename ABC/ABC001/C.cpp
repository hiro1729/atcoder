#include <iostream>
using namespace std;

int main() {
    int deg, dis;
    cin >> deg >> dis;
    int w;
    if (dis < 15) {
        w = 0;
    } else if (dis < 93) {
        w = 1;
    } else if (dis < 201) {
        w = 2;
    } else if (dis < 327) {
        w = 3;
    } else if (dis < 477) {
        w = 4;
    } else if (dis < 645) {
        w = 5;
    } else if (dis < 831) {
        w = 6;
    } else if (dis < 1029) {
        w = 7;
    } else if (dis < 1245) {
        w = 8;
    } else if (dis < 1467) {
        w = 9;
    } else if (dis < 1707) {
        w = 10;
    } else if (dis < 1959) {
        w = 11;
    } else {
        w = 12;
    }
    if (w == 0) {
        cout << "C 0\n";
    } else {
        if (deg <= 112) {
            cout << "N ";
        } else if (deg <= 337) {
            cout << "NNE ";
        } else if (deg <= 562) {
            cout << "NE ";
        } else if (deg <= 787) {
            cout << "ENE ";
        } else if (deg <= 1012) {
            cout << "E ";
        } else if (deg <= 1237) {
            cout << "ESE ";
        } else if (deg <= 1462) {
            cout << "SE ";
        } else if (deg <= 1687) {
            cout << "SSE ";
        } else if (deg <= 1912) {
            cout << "S ";
        } else if (deg <= 2137) {
            cout << "SSW ";
        } else if (deg <= 2362) {
            cout << "SW ";
        } else if (deg <= 2587) {
            cout << "WSW ";
        } else if (deg <= 2812) {
            cout << "W ";
        } else if (deg <= 3037) {
            cout << "WNW ";
        } else if (deg <= 3262) {
            cout << "NW ";
        } else if (deg <= 3487) {
            cout << "NNW ";
        } else {
            cout << "N ";
        }
        cout << w << '\n';
    }
}
