//һ���´ʾ�һ����ȥ��������̨ͤ ��Ϧ�����¼�ʱ�أ�
//�޿��κλ���ȥ��������ʶ�������С԰�㾶���ǻ���
//�������Ϫɳ�� ����
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	float a,b,c,l,s,p;
	cin>>a>>b>>c;
	l=a+b+c;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.2lf %.2lf",l,s);
	return 0;
}

