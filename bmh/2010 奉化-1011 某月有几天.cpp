//һ���´ʾ�һ����ȥ��������̨ͤ��Ϧ�����¼�ʱ�أ�
//�޿��κλ���ȥ��������ʶ�������С԰�㾶���ǻ���
//�������Ϫɳ�� ����
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int year,mouth,day;
	cin>>year>>mouth;
	bool b;
	if ((year%4==0)&&(year%100!=0)||(year%400==0)) b=true; else b=false;
	switch (mouth)
	{
		case 2:if (b==true) day=29; else day=28;break;
		case 4:day=30;break;
		case 6:day=30;break;
		case 9:day=30;break;
		case 11:day=30;break;
		default:day=31;break;
	}
	printf("%d",day);
	return 0;
}
