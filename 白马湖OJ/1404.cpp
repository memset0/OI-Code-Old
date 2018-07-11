#include <iostream>
#include <cstdio>
#include <cstring>
#define move sb001
#define wod sb002
#define key sb003
#define Point sb004
using namespace std;

int n, m, p, k, s, x1, x2, y1, y2, g, x, y, f, r, ans = -1;
int wod[15][15][15][15]; //wall_or_door
int key[15][15]; //key
int cst[15][15];
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct Point/*�洢����+Կ��+ʱ��*/ {
	int x, y, k, t;
}q[100000], u, v;
int get/*���Կ�׺�ѹ��״̬*/(int x, int y) {
	return (x | y);
}
int find/*��ѯ�Ƿ����Կ��*/(int x, int y) {
	return ((x & (1 << (y - 1))) != 0);
}
int main/*������*/() {
	memset(wod, -1, sizeof(wod));
	memset(cst, -1, sizeof(cst));
	memset(key, 0, sizeof(key));
	scanf("%d%d%d", &n, &m, &p);
	scanf("%d", &k);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &g);
		wod[x1][y1][x2][y2] = g;
		wod[x2][y2][x1][y1] = g;
	}
	scanf("%d", &s);
	for (int i = 1; i <= s; i++)
	{
		scanf("%d%d%d", &x, &y, &g);
		key[x][y] |= (1 << (g - 1));
	}
	/* BFS */
	f = 1; r = 1; q[1].x = 1; q[1].y = 1; q[1].k = 0; q[1].t = 0; cst[1][1] = 0;
	while (f <= r)
	{
		//printf("f=%d r=%d\n", f, r);
		u = q[f++];
		//printf("u : x=%d y=%d k=%d t=%d\n", u.x, u.y, u.k, u.t);
		if /*�ж��Ƿ��յ�*/(u.x == n && u.y == m) {ans = u.t; break;}
		u.k |= key[u.x][u.y]; //��õ�ǰλ�õ�Կ��
		for (int i = 0; i < 4; i++)
		{
			v.x = u.x + move[i][0];
			v.y = u.y + move[i][1];
			v.t = u.t + 1;
			v.k = u.k;
			if /*�ж��Ƿ�Խ��*/(v.x < 1 || v.y < 1 || v.x > n || v.y > m) continue;
			if /*˵������ͨ��*/(wod[u.x][u.y][v.x][v.y] == -1 || find(v.k, wod[u.x][u.y][v.x][v.y]))
			{
				if /*����*/((v.k | cst[v.x][v.y]) != cst[v.x][v.y] || cst[v.x][v.y] == -1)
				{
					//printf("v : x=%d y=%d k=%d t=%d\n", v.x, v.y, v.k, v.t);
					cst[v.x][v.y] = v.k;
					q[++r] = v;
					//printf("f=%d r=%d\n", f, r);
				}
			}
			else /*˵��������ͨ��*/ continue; 
		}
	}
	printf("%d", ans);
	return 0;
}
