#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, mod;
	scanf("%d%d%d", &n, &m, &mod);
	long long a[n + 1];
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) {
		int opt, x, y, k;
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d%d%d", &x, &y, &k);
			for (int i = x; i <= y; i++)
				a[i] = (a[i] * k) % mod;
		} else if (opt == 2) {
			scanf("%d%d%d", &x, &y, &k);
			for (int i = x; i <= y; i++)
				a[i] = (a[i] + k) % mod;
		} else {
			long long ans = 0;
			scanf("%d%d", &x, &y);
			for (int i = x; i <= y; i++)
				ans = (ans + a[i]) % mod;
			printf("%lld\n", ans);
		}
	} 
	return 0;
} 
