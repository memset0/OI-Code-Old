#include <bits/stdc++.h> 
using namespace std;
const int maxn = 10010
int n, a[maxn];
char c;
int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		c = getchar();
		if (c == 'b') a[i] = 1;
		else if (c == 'r') a[i] = 2;
		else a[i] = 0;
		a[i + n]  =  a[i];
	}
	for (int i = 1; i <= n; i++)
	
	return 0;
}
