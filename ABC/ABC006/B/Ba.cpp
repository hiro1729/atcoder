// 漸化式に沿って計算 O(N)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[3] = 1;
    for (int i = 4; i <= n; i++) {
        a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10007;
    }
    cout << a[n] << '\n';
}
