#include <bits/stdc++.h>
#define each lalala001
#define sum lalala002
using namespace std;
int n, each, a[25], used[25], sum[10];
void DFS(int cnt, int sum, int i)
{
	//�ж� 
	if (sum == each)
	{
		if (cnt == 3) //�ҵ���
		{
			printf("yes\n");
			exit(0);
		}
		else DFS(cnt + 1, 0, 0) ;
	}
	//DFS 
	for (int j = i; j <= n; j++)
		if (!used[j] && sum + a[j] <= each)
		{
			used[j] = 1;
			DFS(cnt, sum + a[j], j+1);
			used[j] = 0;
		}
}
int main()
{
	//���� 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum[0] += a[i];
	if ((sum[0] % 4) != 0) 
	{
		//�϶�����ƴ��������
		printf("no\n");
		return 0;
	}
	else each = sum[0] / 4;
	//DFS
	DFS(1, 0, 0);
	//���
	printf("no\n");
	return 0;
}
