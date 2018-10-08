#include<bits/stdc++.h>
//#define int long long
//#define double long double
#define endl '\n'
using namespace std;

vector<int> road[3][512];
char name[512][1000];
char x1[3][1000];
int l;
bool rel[3][512][512];
bool vis[512];
int re[512];
int hs[512];

void dfs(int now, int num)//, int hs)
{
	if(vis[now])
	{
		int hsn = 1;
		for(int i = num - 1; i > 0; i--)
		{
			if(hs[i] == 2)
			    hsn = 2;
			for(int j = 1; j <= l; j++)
			{
				if(rel[2][now][j])
				    rel[2][re[i]][j] = 1;
				if(rel[1][now][j])
				    rel[hsn][re[i]][j] = 1;
			}
		}
		return ;
	}
	vis[now] = 1;
	re[num] = now;
	int hsn = 1;
    for(int i = num - 1; i > 0; i--)
    {
    	if(hs[i] == 2)
    	    hsn = 2;
    	rel[hsn][re[i]][now] = 1;
	}
	//if(hs == 1)
	hs[now] = 1;
	    for(int i = 0; i < road[1][now].size(); i++)
	        dfs(road[1][now][i], num+1);//, hs);
	hs[now] = 2;
	for(int i = 0; i < road[2][now].size(); i++)
	    dfs(road[2][now][i], num+1);//, 2);
}


signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
    	cin >>x1[1] >> x1[0] >> x1[2];
    	int p[3];
    	for(int j = 1; j <= 2; j++)
    	{
    		for(p[j] = 1; p[j] <= l; p[j]++)
    			if(strcmp(name[p[j]], x1[j]) == 0)
    			    break;
			if(p[j] > l)
			{
				l++;
				strcpy(name[l], x1[j]);
			}
		}
		if(strcmp(x1[0], "is-a") == 0)
		    p[0] = 1;
		else
		    p[0] = 2;
		road[p[0]][p[1]].push_back(p[2]);
	}
	for(int i = 1; i <= l; i++)
	    rel[1][i][i] = 1;
	//cout <<  l << endl;
	//for(int i = 1; i <= l; i++)
	//   cout << i << ' ' << name[i] << endl;
	for(int i = 1; i <= l; i++)
	{
		dfs(i, 1);//, 1);
	}

	for(int i = 1; i <= m; i++)
    {
    	cin >>x1[1] >> x1[0] >> x1[2];
    	int p[3];
    	for(int j = 1; j <= 2; j++)
    	{
    		for(p[j] = 1; p[j] <= l; p[j]++)
    			if(strcmp(name[p[j]], x1[j]) == 0)
    			    break;
		}
		if(strcmp(x1[0], "is-a") == 0)
		    p[0] = 1;
		else
		    p[0] = 2;
		//cout << p[0] << ' ' << p[1] << ' ' << p[2] << endl;
		if(rel[p[0]][p[1]][p[2]])
		    cout << "Query " << i << ": true" << endl;
		else
		    cout << "Query " << i << ": false" << endl;
	}
    return 0;
}

// 4 4
// a is-a b
// b is-a c
// b has-a d
// d is-a e
// a is-a e
// a has-a e
// c has-a e
// c is-a e
