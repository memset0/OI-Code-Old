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
	char s[4];
	scanf("%s",s+1);
	char a=s[1],b=s[2],c=s[3],t;
	if (a>b) {t=a;a=b;b=t;}
	if (a>c) {t=a;a=c;c=t;}
	if (b>c) {t=b;b=c;c=t;}
	printf("%c%c%c",a,b,c);
	return 0;
}

