#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
char chr; int ret;
void read() {
	chr = getchar(), ret = 0;
	while (!isdight(chr)) chr = getchar();
	while (isdight(chr)) ret = ret * 10 + chr - '0', chr = getchar();
	return ret;
}
int n, m, rt;
struct Question {
	int u, v, ans;
} q[maxn];
vector < int > g[maxn];
int main() {
	n = read(), m = read(), rt = read();
	int x, y;
	for (int i = 1; i <= m; i++) {
		x = read(), y = read();
		
	}
	return 0;
}
