#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int MAXN = 50;

char rec[MAXN][MAXN];
bool g[MAXN*MAXN][MAXN*MAXN];
bool b[MAXN*MAXN];
int h, w, ans, total;
int mylink[MAXN*MAXN];
int r[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool find(int a)
{
	for(int i = 0; i < h * w; i++)
	{
		if(g[a][i] == true && !b[i])
		{
			b[i] = true;
			if(mylink[i] == 0 || find(mylink[i]) )
			{
				mylink[i] = a;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int cas, total;
	scanf("%d", &cas);
	while(cas --)
	{
		memset(g, false, sizeof(g));
		memset(mylink, 0, sizeof(mylink));
		total = ans = 0;
		scanf("%d%d", &h, &w);
		getchar();
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				rec[i][j] = getchar();
				if(rec[i][j] == '*') total++;
			}
			getchar();
		}
		for(int i = 0; i < h; i++)
			for(int j = 0;  j < w; j++)
				for(int k = 0; k < 4; k++)
				{
					int xx = i + r[k][0];
					int yy = j + r[k][1];
					if(rec[i][j] == '*' && rec[xx][yy] == '*' &&  xx >= 0 && yy >= 0 && xx < h && yy < w)
						g[i * w + j][xx * w + yy] = g[xx * w +yy][i * w + j] = true;
				}
		for(int i = 0; i < h * w; i++)
		{
			memset(b, false, sizeof(b));
			if(find(i)) ans++;
		}
		ans /= 2;
		printf("%d\n", total - ans);
	}
    return 0;
}