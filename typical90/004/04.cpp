#include <iostream>
#include <vector>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>> A(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
		}
	}

	vector<int> B(H), C(W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			B[i] += A[i][j];
			C[j] += A[i][j];
		}
	}

	vector<vector<int>> ans(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			ans[i][j] = B[i] + C[j] - A[i][j];
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << ans[i][j];
			if (j != W - 1) {
				cout << ' ';
			}
		}
		cout << '\n';
	}
}