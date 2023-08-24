#include <stdio.h>

int c[300030];
int l = 100010, r = 100010;

int main() {
	int q, t, x;
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &t, &x);
		if (t == 1) c[--l] = x;
		if (t == 2) c[r++] = x;
		if (t == 3) printf("%d\n", c[l + x - 1]);
	}
}