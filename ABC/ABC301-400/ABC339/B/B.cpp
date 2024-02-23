#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W, N;
	cin >> H >> W >> N;
	vector<string> A(H, string(W, '.'));
	int nowx = 0, nowy = 0, dx = -1, dy = 0;
	for (int i = 0; i < N; i++) {
		if (A[nowx][nowy] == '.') {
			swap(dx, dy);
			dy = -dy;
			A[nowx][nowy] = '#';
		}
		else {
			swap(dx, dy);
			dx = -dx;
			A[nowx][nowy] = '.';
		}
		nowx += dx + H;
		nowy += dy + W;
		nowx %= H;
		nowy %= W;
	}
	for (string i: A) {
		cout << i << '\n';
	}
}