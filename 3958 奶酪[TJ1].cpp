#include<bits/stdc++.h>//����ͷ����ò�Ҫ��
using namespace std;//���ӱ���
int f[1001];//���鼯
int find(int x){
    if (x!=f[x]) f[x]=find(f[x]);
    return f[x];
}//����+·��ѹ��
double dis(long long x,long long y,long long z,long long x1,long long y1,long long z1){
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1));
}//������빫ʽ
long long x[100001],y[100001],z[100001];
int f1[100001],f2[100001];
//f1��¼�붥���ཻ�Ķ������
//f2��¼������ཻ�Ķ������
int main(){
	freopen("testdata.in", "r", stdin);
    int t;
    scanf("%d",&t);
    int n,h; 
    long long r;
    for (int i=1;i<=t;i++){
        scanf("%d%d%ld",&n,&h,&r);//long long�����Ļ�...
        int tot1=0;//��¼�붥���ཻ�Ķ��м���
        int tot2=0;//��¼������ཻ�Ķ��м���
        for (int j=1;j<=n;j++){
          f[j]=j;  //���鼯��ʼ��
         }
        for (int j=1;j<=n;j++){
            scanf("%ld%ld%ld",&x[j],&y[j],&z[j]);//long long�����Ļ�...
            if (z[j]+r>=h){//�ж�������Ƿ��붥���ཻ
                tot1++;
                f1[tot1]=j;
            }
            if (z[j]-r<=0){//�ж�������Ƿ�������ཻ
                tot2++;
                f2[tot2]=j;
            }
            for (int k=1;k<=j;k++){//ö��֮ǰ�Ķ��Ƿ���������ཻ������ཻ��ϲ�����
                if (dis(x[j],y[j],z[j],x[k],y[k],z[k])<=2*r){
                    int a1=find(j);
                    int a2=find(k);
                    if (a1!=a2)
                      f[a1]=a2;
                }
            }
        }
        int s=0;
        //����ÿһ�����Ƿ��ж�����������
        for (int j=1;j<=tot1;j++){
            for (int k=1;k<=tot2;k++){
                if (find(f1[j])==find(f2[k])){
                    s=1; 
                    break;
                }
            }
            if (s==1) break;
        }
        if (s==1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        
		vector < int > t[1010];
		for (int i = 1; i <= n; i++)
			t[find(i)].push_back(i);
		for (int i = 1; i <= n; i++)
			if (t[i].size()) {
				printf("%4d:", i);
				for (int j = 0; j < t[i].size(); j++)
					printf(" %d", t[i][j]);
				puts("");
			}
    }
    return 0;
} 
