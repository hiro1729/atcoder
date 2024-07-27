#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W, Si, Sj;
	cin >> H >> W >> Si >> Sj;
	Si--;
	Sj--;
	vector<string> C(H);
	for (int i = 0; i < H; i++) {
		cin >> C[i];
	}
	string X;
	cin >> X;
	for (char dir: X) {
		if (dir == 'U') {
			if (Si > 0 && C[Si - 1][Sj] == '.') {
				Si--;
			}
		}
		if (dir == 'D') {
			if (Si < H - 1 && C[Si + 1][Sj] == '.') {
				Si++;
			}
		}
		if (dir == 'L') {
			if (Sj > 0 && C[Si][Sj - 1] == '.') {
				Sj--;
			}
		}
		if (dir == 'R') {
			if (Sj < W - 1 && C[Si][Sj + 1] == '.') {
				Sj++;
			}
		}
	}
	cout << Si + 1 << ' ' << Sj + 1 << '\n';
}