#include <bits/stdc++.h> 
#define MAXN 10
using namespace std;
using namespace std;
int a[MAX], book[MAX], out[MAX], N, Ans;
void dfs(int x){
    //�ж��˳�����
    if (x > N) {
        ++Ans;
        for (int i = 1; i <= N; i++){
            cout << out[i] << " ";
        }
        cout << endl;
        return;
    }
    //������ô��
    for (int i = 1; i <= N; i++){
        if (book[i]) continue;
        book[i] = 1;
        out[x] = a[i];     
        dfs(x + 1);
        book[i]= 0;
    }
}
int main()
{
    cin >> N;
    for (int i =1; i <= N; i++){
        cin >> a[i];     
    }
    //���ݳ�ʼ��
    Ans = 0;
    for (int i = 1; i <= N; i++){
        book[i] = out[i] = 0;
    }
    cout << "Case #" << t << endl;
    //�ݹ麯������
    dfs(1);

    //������
    cout << Ans << endl;
    return 0;
}
