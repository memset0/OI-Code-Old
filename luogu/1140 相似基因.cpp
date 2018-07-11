#include <bits/stdc++.h>
using namespace std;
const int maxn = 110, c[5][5] = {
    {-10000, -3, -4, -2, -1}, 
    {-3, 5, -1, -2, -1}, 
    {-4, -1, 5, -3, -2}, 
    {-2, -2, -3, 5, -2}, 
    {-1, -1, -2, -2, 5}
}; //���ݱ� 
int n, m, a[maxn], b[maxn], f[maxn][maxn]; //f[i][j]��ʾA��ǰi����B��ǰj����������ƶ� 
char s1[maxn], s2[maxn];
int main() {
    scanf("%d%s%d%s", &n, s1 + 1, &m, s2 + 1);
    for (int i = 1; i <= n; i++)
        if (s1[i] == 'A') a[i] = 1;
        else if (s1[i] == 'C') a[i] = 2;
        else if (s1[i] == 'G') a[i] = 3;
        else if (s1[i] == 'T') a[i] = 4;
    for (int i = 1; i <= m; i++)
        if (s2[i] == 'A') b[i] = 1;
        else if (s2[i] == 'C') b[i] = 2;
        else if (s2[i] == 'G') b[i] = 3;
        else if (s2[i] == 'T') b[i] = 4; //���� 
    f[0][0] = 0; //��ʼ�� - һ���㶼��ȡ������0 
    for (int i = 1; i <= n; i++)
        f[i][0] = f[i - 1][0] + c[a[i]][0];
    for (int i = 1; i <= m; i++)
        f[0][i] = f[0][i - 1] + c[0][b[i]]; //����߽�	��� 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = max(
                f[i - 1][j - 1] + c[a[i]][b[j]], max( //����ȡ
                f[i][j - 1] + c[0][b[j]], //ȡһ����һ��
                f[i - 1][j] + c[a[i]][0])); //��һ��ȡ��һ�� 
    cout << f[n][m] << endl; //��� 
    return 0;
}
