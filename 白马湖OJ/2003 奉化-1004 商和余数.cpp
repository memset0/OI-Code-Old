//����Ѱ��ǧ�ٶȣ���Ȼ���ף�����ȴ�ڵƻ���ɺ�����������������񰸡� 
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int m,n,k,r;
	cin>>m>>n; 
	k=m/n;
	r=m-n*k;
	printf("%d\n%d",k,r);
	return 0;
}
