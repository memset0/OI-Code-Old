#include <bits/stdc++.h> 
using namespace std;
const int maxn = 5010;
int n, a[maxn], f[maxn], g[maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), f[i] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i - 1; j++)
			if (a[i] < a[j])
				f[i] = max(f[i], f[j] + 1);
	int maxx = 0;
	for (int i = 1; i <= n; i++)
		maxx = max(maxx, f[i]);
	cout << maxx << " ";
	for (int i = 1; i <= n; i++)
		if (f[i] == 1)
			g[i] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i - 1; j++)
			if (a[i] == a[j] && f[i] == f[j])
				g[j] = 0;
			else if (a[j] > a[i] && f[i] == f[j] + 1)
				g[i] += g[j];
	int summ = 0;
	for (int i = 1; i <= n; i++)
		if (f[i] == maxx)
			summ += g[i];
	cout << summ << endl;
	return 0;
}


//������ 
//#include<iostream>
//#include<cstdio>
//using namespace std;
//int n,g[10000],f[10000],a[10000];
//int main()
//{
//    scanf("%d",&n);
//    int i,j;
//    for (i=1;i<=n;i++)
//      {scanf("%d",&a[n-i+1]);f[i]=1;}
//    for (i=2;i<=n;i++)
//      for (j=1;j<=i-1;j++)
//        if (a[j]<a[i])
//          f[i]=max(f[i],f[j]+1);
//    for (i=1;i<=n;i++)
//      if (f[i]==1)
//        g[i]=1;//�������Ϊ1�Ļ���ֻ����һ�ֿ��ܣ���ע�ⲻ��ȫ����ֵ��1��Ϊ���Ȳ�Ϊ1���ǰ���ۼӣ�����g[i]�ͻ�+1
//    for (i=2;i<=n;i++)
//      for (j=1;j<=i-1;j++)
//        if (a[i]==a[j]&&f[i]==f[j])
//          g[j]=0;//��ĿҪ��ȥ�أ����������������һ�����ҵ����ǵ�����������еĳ���һ����ȥ��һ���������û��ȥ��ֻ�ܹ�������
//        else
//          if (a[j]<a[i]&&f[j]+1==f[i])
//            g[i]+=g[j];//�����jλ����������Ϊһ�������������е�i������ǰ�����Ͱѵ���j�����������и����ۼӵ�����i�����������и�����
//    int ans1=0,ans2=0;
//    for (i=1;i<=n;i++)
//      ans1=max(ans1,f[i]);
//    for (i=1;i<=n;i++)
//      if (f[i]==ans1)
//        ans2+=g[i];
//    printf("%d %d",ans1,ans2);
//}
