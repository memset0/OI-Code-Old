//�������ҵ�������//
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[50000];  //ÿ�ַ������±�洢 
int k[20];    //���ڴ洢*��λ�� 
int f1(char[]);              //���������ַ���ת��Ϊʮ�������� 
int f2(int, int, char[]);    //��ʮ���Ʊ������ɶ�Ӧ�ĵ����ַ��� 
int f3(int);                 //�������Ӧ�ı������� 
int fun(char[]);             //�������� 
int main()
{
	int n, m;
	char str[20];
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		fun(str);
	}
	int ans = 0;
	for (int i = 0; i <= 50000; i++) 
	{
		if (a[i] != 0)
		{
			//printf("RUNNING function main()[tab 1][WYL][%d]\n", i);
			ans ++;
		}
		//printf("RUNNING function main()[tab 2][WYL][%d]\n", i);
	}
	cout << ans;
	return 0;
}
int fun(char s[])
{
	int l = strlen(s);
	int kn = 0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == '*')
		{
			kn ++;
			k[kn] = i;
		}
	}
	if (kn == 0) //��û��*�ŵ���� 
	{
		a[f1(s)] = 1;
		//printf("RUNNING function fun()[tab 2][WYL][%d]\n", f1(s));
		return 0;
	}
	int kn_max = f3(kn);
	for (int i = 0; i < kn_max; i++)
	{
		//printf("RUNNING function fun()[tab 1][WYL]\n");
		f2(i, kn, s);
	}
	return 0;
}
int f1(char s[])
{
	int l = strlen(s);
	int k = 1;
	int ret = 0;
	for (int i = (l - 1); i >= 0; i--)
	{
		char c = s[i];
		if (c == '1') ret = ret + k * 1;
		else if (c == '0');
		k = k * 2;
	}
	return ret;
}
int f2(int key_k, int kn, char s[])
{
	//printf("RUNNING function f2()[tab 1][WYL]\n");
	char key[20] = "                   ";
	char str[20] = ""; 
	int t = key_k;
	int d;
	int i = kn;
	while (i > 0)
	{
		d = t % 2;
		t = t / 2; 
		key[k[i]] = d + '0';
		i--;
	}
	for (int i = 0; i < strlen(s); i++)
	{
		//printf("RUNNING function f2()[tab 2][WYL]\n");
		if ((s[i] == '*' && key[i] == ' ') || (s[i] != '*' && key[i] != ' '))
		{ //������������� 
			printf("Error!![From function f2()][WYL]\n");
		}
		else if (s[i] == '*')
		{ //�������(*��)���滻	   
			str[i] = key[i];
		}
		else
		{ //�������(��*)���滻 
			str[i] = s[i];
		}
	}
	a[f1(str)] ++;
}
int f3(int n)
{
	int ret = 1;
	for (int i = 1; i <= n; i++) ret *= 2;
	return ret;
}
