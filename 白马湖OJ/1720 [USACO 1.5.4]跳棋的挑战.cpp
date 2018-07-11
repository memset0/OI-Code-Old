#include <iostream>
 
#include <vector>
 
using namespace std;
 
 
 
 
 
typedef unsigned long long ULL;//���֧��64�ʺ�
 
 
 
ULL n = 8;
 
ULL ANS;
 
ULL ans = 0;
 
 
 
vector<vector<ULL> > aa;
 
void dfs ( ULL col, ULL diag1, ULL diag2, vector<ULL> &a )
 
{
 
    if ( col == ANS )
 
    {
 
        if ( aa.size() < 3 )
 
            aa.push_back ( a );//���
 
        ++ans;
 
        return;
 
    }
 
    ULL can_put = ANS & ~ ( col | diag1 | diag2 );//���Էŵ�λ����1
 
    while ( can_put )
 
    {
 
        ULL curcol = can_put & ( -can_put ) ;//ȡ���λ��1������ÿ��ѡ�����λ�����Դ����ֵ������
 
        can_put &= ~curcol;//���Էŵ�ɾȥ��ǰѡ���
 
        a.push_back ( curcol );//ѹ���
 
        dfs ( col | curcol, ( diag1 | curcol ) << 1 & ANS, ( diag2 | curcol ) >> 1, a );
 
        a.pop_back ( );//����
 
    }
 
}
 
 
 
int main()
 
{
 
    cin >> n;
 
    ANS = ( 1 << n ) - 1;
 
    vector<ULL> tmp;
 
    dfs ( 0, 0, 0, tmp );
 
    for ( unsigned i = 0; i < aa.size(); ++i )
 
    {
 
        for ( unsigned j = 0; j < n; ++j )
 
        {
 
            ULL k = aa[i][j];
 
            int l = 1;
 
            while ( k >>= 1 )//ͳ�ƽ����1��λ��
 
                ++l;
 
            cout << l << " ";
 
        }
 
        cout << endl;
 
    }
 
 
 
    cout << ans << endl;
 
    return 0;
 
}