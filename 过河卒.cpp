#include <bits/stdc++.h> 
using namespace std;
const int maxn = 100;
const int mov[16] = {1, 2, 2, 1, -1, 2, 2, -1, 1, -2, -2, 1, -1, -2, -2, -1};
int n, m, x, y, a, b;
int map[maxn];
int main() {
	cin >> n >> m >> x >> y;
	for (int i = 0; i < 8; i++)
		map[x + mov[2 * i]][y + mov[2 * i + 1]] = -1;
	if (n == 0 || m == 0) {
		cout << 1 << endl;
		return 0; 
	}
	if (n > 0 && m > 0) a = 1, b = 1;
	if (n > 0 && m < 0) a = 1, b = -1;
	if (n < 0 && m > 0) a = -1, b = 1;
	
	return 0;
} 
