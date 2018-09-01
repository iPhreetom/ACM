#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define LL long long
#define row(a, s, e) for(int a = s; a <= e; ++a)
#define wor(a, s, e) for(int a = s; a >= e; --a)
#define rowd(a, s, e, d) for(int a = s; a <= e; a += d)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define MOD (1000000007)
//#define endl '\n'
struct pnt{
	LL x, y, v, to, re;
}p[112345];

bool cmp(pnt x, pnt y)
{
	if(x.x < y.x)
	    return 1;
	else if(x.x == y.x && x.y < y.y)
	    return 1;
	return 0;
}
int n;
LL dfs(int now)
{
	if(p[now].re == -1)
	{
		p[now].re = 0;
		row(i, now + 1, n)
		{
			if(p[now].y < p[i].y && p[now].x < p[i].x)
			    p[now].re = max(p[now].re, dfs(i));
		}
		p[now].re += p[now].v;
	}
	return p[now].re;
}

int main ()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i].x >> p[i].y >> p[i].v;
			p[i].to = p[i].re = -1;
		}
		p[0].x = p[0].y = p[0].v = 0;
		p[0].re = p[0].to = -1;
		sort(p + 1, p + n + 1, cmp);
		cout << dfs(0) << endl;
	}
    return 0;
}
