#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n = 2025 - n;
	for (int i = 1; i <= 9; i++) {
		if (n % i == 0 && n / i < 10) {
			printf("%d x %d\n", i, n / i);
		}
	}
}