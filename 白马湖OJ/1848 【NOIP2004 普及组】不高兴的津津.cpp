#include<stdio.h>
#define INF 100//����һ���Ƚϴ��ֵ
int main()
{
    int days[10];//�������飬���������һЩ�ռ�
    int am,pm,time,day,max=-INF,maxn;//��max�㹻С�Ա�Ƚ�
    for(day=1;day<=7;day++)
  /*��Ȼ����Ӧ�ô�0��ʼ��������Ϊ��������ڼ�����ֱ����1��ʾ����һ*/
    {
      scanf("%d %d",&am,&pm);//�������Ϻ������ʱ��
      days[day]=am+pm;//������������һ��
      if(days[day]<8) days[day]=0;//�ж����᲻�᲻���ģ���������õ�����0
      if(days[day]>max)//�Ƚϵó����ֵ
         {
          max=days[day];
          maxn=day;
          }
    }
    if(max==0) printf("%d",max);//�����û��һ�첻�������0
       else printf("%d",maxn);//�����������ĵ�����
  return 0;
}