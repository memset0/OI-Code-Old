#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int n, a[maxn][maxn] = {0}, x[maxn * maxn], y[maxn * maxn];
int main() {
	scanf("%d", &n);
	a[1][(1 + n) / 2] = 1;
	x[1] = 1, y[1] = (1 + n) / 2;
	for (int i = 2; i <= n * n; i++) {
		if (x[i - 1] == 1 && y[i - 1] != n) {
			//(K-1)�ڵ�һ�е��������һ��
			//��K�������һ�У�(K-1)�����е���һ��
			x[i] = n, y[i] = y[i - 1] + 1;
			a[x[i]][y[i]] = i;
		} else if (x[i - 1] != 1 && y[i - 1] == n) {
			//(K-1)�����һ�е����ڵ�һ��
			//��K���ڵ�һ�У�(K-1)�����е���һ��
			x[i] = x[i - 1] - 1, y[i] = 1;
			a[x[i]][y[i]] = i;
		} else if (x[i - 1] == 1 && y[i - 1] == n) {
			//(K-1)�ڵ�һ�����һ��
			//��K����(K-1)�����·�
			x[i] = x[i - 1] + 1, y[i] = y[i - 1];
			a[x[i]][y[i]] = i;
		} else if (x[i - 1] != 1 && y[i - 1] != n) {
			//(K-1)�Ȳ��ڵ�һ�У�Ҳ�������һ��
			if (a[x[i - 1] - 1][y[i - 1] + 1] == 0) {
				//(K-1)�����Ϸ���δ����
				//��K����(K-1)�����Ϸ�
				x[i] = x[i - 1] - 1, y[i] = y[i - 1] + 1;
				a[x[i]][y[i]] = i;
			} else {
				//(K-1)�����Ϸ�������
				//��K����(K-1)�����·�
				x[i] = x[i - 1] + 1, y[i] = y[i - 1];
				a[x[i]][y[i]] = i;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}

