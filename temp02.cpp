#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, y, z;
	for (int a = 0; a <= 100; a += 10)
		for (int b = 0; b <= 100; b += 10)
			for (int c = 0; c <= 100; c += 10) {
				x = a * 0.2 + b * 0.3 + c * 0.5;
				y = a / 10 * 2 + b / 10 * 3 + c / 10 * 5;
				z = a * 0.2;
				z += b * 0.3;
				z += c * 0.5;
				if (x != y) {
					printf("%d %d %d %d %d\n", a, b, c, x, y);
				}
			}
	return 0;
}
