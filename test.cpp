#include <bits/stdc++.h> 
#define max2 max

using namespace std;

int max4(int, int, int, int);

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max4(a, b, c, d);
}

int max4(int a, int b, int c, int d) {
	int m = max2(a, b);
	m = max2(m, c);
	m = max2(m, d);
	return m;
}
