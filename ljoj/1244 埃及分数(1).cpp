#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
 
typedef long long LL;
int maxd;
int a, b;
const int maxn = 10010;
int ans[maxn], v[maxn];
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
int get_first(int a, int b)//�ҵ�1/c��a/bʱ��С��c
{
	int c = 1;
	while (b > a*c)c++;
	return c;
}
bool better(int d)//�Ƚ����Ϊdʱ�������ҵ��Ľ��ǲ��Ǹ��ŵ�
{
	for (int i = d; i >= 0; i--)
	if (v[i] != ans[i])
	{
		return ans[i] == -1 || v[i] < ans[i];//���������˵����ǰ���ţ�(1)��ʱ��δ�ҵ����⣻(2)��ǰ�ķ�ĸС��ԭ���ķ�ĸ��˵����ǰ�ķ�����ԭ���ĸ��󣬷�������Ҫ��
	}
	return false;
}
 
bool dfs(int d, int from, LL aa, LL bb)//��ǰ���Ϊd,��ĸ����С��from,����֮��ǡ����aa/bb
{
	if (d == maxd)//���������һ��
	{
		if (bb%aa)return false;//����������˵�����һ����ϰ��������Ķ��壬ʧ���˳�
		v[d] = bb / aa;
		if (better(d))memcpy(ans, v, sizeof(LL)*(d + 1));//��ǰ�ҵ��Ľ��Ǹ��ŵģ�����ans
		return true;
	}
	bool ok = false;
	from = max(from, get_first(aa, bb));//����from
	for (int i = from;; i++)//ö�ٷ�ĸ
	{
		if (bb*(maxd + 1 - d) <= i*aa)break;//�����ֹ۹��ۺ�������֦���ӵ�ǰ���d����maxdһ����maxd-d+1����(maxd-d+1)*(1/i)���ղ���aa/bb����Ҫ��֦
		v[d] = i;
		LL b2 = bb*i;//����aa/bb-1/i��ͨ�ֺ󣬷�ĸ��bb*i����ĸ��aa*i-bb
		LL a2 = aa*i - bb;
		LL g = gcd(a2, b2);//������ӣ���ĸ�����Լ��������Լ��
		if (dfs(d + 1, i + 1, a2 / g, b2 / g))ok = true;
	}
	return ok;
}
 
int main()
{
//	freopen("INPUT", "r", stdin);
	int ok = 1;
	scanf("%d%d", &a, &b);//�������a/b
	for (maxd = 1;; maxd++)
	{
		memset(ans, -1, sizeof(ans));
		if (dfs(0, get_first(a, b), a, b)){ ok = 1; break; }
	}
	for (int i = 0;; i++)
	if (ans[i]>0)
		printf("%d ", ans[i]);
	else { printf("\n"); break; }
	return 0;
}

