//һ���´ʾ�һ����ȥ��������̨ͤ��Ϧ�����¼�ʱ�أ�
//�޿��κλ���ȥ��������ʶ�������С԰�㾶���ǻ���
//�������Ϫɳ�� ����
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n=(n+1)%7;
	char s[40];
	switch (n)
	{
		case 0:cout<<"Sunday";break;
		case 1:cout<<"Monday";break;
		case 2:cout<<"Tuesday";break;
		case 3:cout<<"Wednesday";break;
		case 4:cout<<"Thursday";break;
		case 5:cout<<"Friday";break;
		case 6:cout<<"Saturday";break;
	}
	cout<<endl;
	return 0;
}
