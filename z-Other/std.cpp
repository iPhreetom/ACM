#include<bits/stdc++.h>
#define MAXN 1109

using namespace std;

int n,m;
char ch[MAXN][MAXN];
int La[MAXN][MAXN];
int a[MAXN][MAXN];

int Find2(int x,int y,int z);
int Find3(int x,int y,int z);
long long Ans;

int Find1(int x,int y)
{
	int X = La[x][y];
	if(X==n) return 0;

	return Find2(X+1,y,X - x);
}
int Find2(int x,int y,int z)
{
	int X = La[x][y];
	if(X==n) return 0;
	if(X-x!=z) return 0;
	return Find3(X+1,y,z);
}
int Find3(int x,int y,int z)
{
	int X = La[x][y];
	if(X-x<z) return 0;
	return x + (z);
}

bool Check(int x,int y)
{
	if(a[x][y-1]==0) return false;
	if(a[x][y]!=a[x][y-1]) return false;
	int z = (a[x][y] - x + 1) / 3;

	if(ch[x][y]!=ch[x][y-1]) return false;
	if(ch[x+z][y]!=ch[x+z][y-1]) return false;
	if(ch[x+z+z][y]!=ch[x+z+z][y-1]) return false;
	return true;
}
bool color(int x,int y)
{
	int z = (a[x][y] - x + 1) / 3;
	if(ch[x][y]==ch[x+z][y]) return false;
	if(ch[x+z][y]==ch[x+z+z][y]) return false;
	return true;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",ch[i]+1);

	for(int j=1;j<=m;j++)
	{
		La[n][j] = n;
		for(int i=n-1;i;i--)
		{
			if(ch[i][j]==ch[i+1][j]) La[i][j] = La[i+1][j];
			else La[i][j] = i;
		}
	}

	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			a[i][j] = Find1(i,j);
			if(a[i][j]&&!color(i,j)) a[i][j]=0;
		}
	}
	long long Cnt;
	for(int i=1;i<=n;i++)
	{
		Cnt = 0;

		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==0)
			{
				Ans += (Cnt) * (Cnt + 1) / 2;
				Cnt = 0;
			}
			else
			{
				if(Check(i,j)) Cnt++;
				else
				{
					Ans += (Cnt) * (Cnt + 1) / 2;
					Cnt = 1;
				}
			}
		}
		Ans += (Cnt) * (Cnt + 1) / 2;
	}
	printf("%I64d",Ans);

	return 0;
}
