#include<bits/stdc++.h>
//#define int long long
#define double long double
#define endl '\n'
using namespace std;


bool zss[1123456];
int zs[112345], lzs;
void pre(){
	for(int i = 2; i <= 1000000; i++)
	    if(!zss[i])
	    {
	    	for(int j = 2 * i; j <= 1000000; j += i)
	            zss[j] = 1;
	        zs[++lzs] = i;
		}
}

int n;
int a[11234];
int b[3][11234];
vector<int> line[3][11234];
void link(int s1, int s2)
{
	line[1][s1].push_back(s2);
	line[2][s2].push_back(s1);
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	pre();
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			line[1][i].clear();
			line[2][i].clear();
		}
		b[2][0] = b[1][0] = 0;
		for(int i = 1; i <= n; i++)
		{
			char x;
			cin >> x;
			if(x == 'M')
			    b[1][++b[1][0]] = a[i];
			else
			    b[2][++b[2][0]] = a[i];
		}
		for(int i = 1; i <= lzs; i++)
		{
			int s1 = -1, s2 = -1;
			for(int j = 1; j <= b[1][0]; j++)
			    if(b[1][j] % zs[i] == 0)
			    {
			    	s1 = j;
			    	break;
				}
			if(s1 == -1)
			    continue;
			for(int j = 1; j <= b[2][0]; j++)
			    if(b[2][j] % zs[i] == 0)
			    {
			    	s2 = j;
			    	break;
				}
			if(s2 != -1)
			    link(s1, s2);
		}
	}
    return 0;
}
