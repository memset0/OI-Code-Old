//һ���´ʾ�һ����ȥ��������̨ͤ��Ϧ�����¼�ʱ�أ�
//�޿��κλ���ȥ��������ʶ�������С԰�㾶���ǻ���
//�������Ϫɳ�� ����
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	int n,m;
	int a,b,c;
	cin>>n;
	c=n%10; b=n/10%10; a=n/100%10;
	m=c*100+b*10+a;
	cout<<m;
	return 0;
}

