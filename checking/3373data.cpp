#include <bits/stdc++.h>
using namespace std;
int r(int limit) {
	return (rand() % limit + 1);
}
int main() {
	srand(time(0));
	int n = 3, m = 3, mod = 5, lim = 5;
	printf("%d %d %d\n", n, m, mod);
	for (int i = 1; i <= n; i++)
		printf("%d ", r(lim) % mod);
	printf("\n");
	for (int i = 1; i <= m; i++) {
		int opt = r(3), x = r(n), y = r(n);
		if (x > y) swap(x, y);
		if (opt == 1) printf("%d %d %d %d\n", opt, x, y, r(lim));
		else if (opt == 2) printf("%d %d %d %d\n", opt, x, y, r(lim));
		else if (opt == 3) printf("%d %d %d\n", opt, x, y);
	}
	return 0;
}
