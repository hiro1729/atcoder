#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int h = n / 3600, m = (n % 3600) / 60, s = n % 60;
	printf("%02d:%02d:%02d", h, m, s);
}