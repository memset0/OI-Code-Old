#include <bits/stdc++.h> 
using namespace std;
const int maxn = 200010;
struct TreeChild {
	int l, r, m;
	long long v;
};
struct Tree {
	TreeChild p[maxn];
	long long build(int u, int left, int right) {
		p[u].l = left, p[u].r = right, p[u].m = (left + right) / 2;
		if (left == right) return ;
		build(u << 1, left, p[u].m);
		build((u << 1) + 1, p[u].m + 1, right);
	}
	long long add(int u, int left, int right, int val) {
		if (val > p[u].v) p[u].v = val;
		if (p[u].l == p[u].r) return ;
		if (right <= p[u].m) add(u << 1, left, right, val);
		else if (left > p[u].m) add((u << 1) + 1, left, right, val);
		else {
			add(u << 1, left, p[u].m, val);
			add((u << 1) + 1, p[u].m + 1, right, val);
		}
	}
	long long find(int u, int left, int right) {
		if (p[u].l == left && p[u].r == right) return p[u].v;
		if (right <= p[u].m) return find
	}
} t;
int main() {
	return 0;
}
