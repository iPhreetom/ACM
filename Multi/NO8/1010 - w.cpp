#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;
#define LL long long
#define row(a, s, e) for(int a = s; a <= e; ++a)
#define wor(a, s, e) for(int a = s; a >= e; --a)
#define rowd(a, s, e, d) for(int a = s; a <= e; a += d)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define MOD (998244353)
#define endl '\n'
int a[100050],len;
int s[100050];
pair<int, int> b[100050];
vector<pair<int, int> > lo[100050];

namespace fastIO
{
#define BUF_SIZE 1048576

    inline char nc()
    {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if (p1 == pend)
        {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            assert(pend != p1);
        }
        return *p1++;
    }

    inline bool blank(char c) { return c == ' ' || c == '\n' || c == '\r' || c == '\t'; }

    // non-negative integer
    inline int getint()
    {
        int x = 0;
        char c = nc();
        while (blank(c)) c = nc();
        for (; c >= '0' && c <= '9'; c = nc()) x = x * 10 + c - '0';
        return x;
    }

    // integer
    // inline int getint()
    // {
    //     int x = 0, sgn = 1;
    //     char c = nc();
    //     while (blank(c)) c = nc();
    //     if (c == '-') sgn = -1, c = nc();
    //     for (; c >= '0' && c <= '9'; c = nc()) x = x * 10 + c - '0';
    //     return sgn * x;
    // }

#undef BUF_SIZE
};
using namespace fastIO;


int findstrg(int x)
{
    if(x > b[len].second)
        return len;
    if(x < b[2].second)
        return 1;

	int p  = lower_bound(b,b+len+1,make_pair(x,1)) - b;
	cout<<"p = "<<p<<endl;

	int l = 1, r = len;
    while(r > l + 1)
    {
        int m = (l + r) / 2;
        if(x > b[m].second)
            l = x;
        else
            r = x;
    }
	cout<<"l = "<<l<<endl;


    return l;
}
int findbig(int now, int l, int r, int y)
{
    if(y >= lo[now][r].first)
        return 0;
    if(y < lo[now][l].first)
        return lo[now].size() - 1;
    int lst = r;

	int p = lower_bound(lo[now].begin()+l+1,lo[now].begin()+r+1,make_pair(y,1)) - lo[now].begin();
	cout<<"lst - p = "<<lst - p<<endl;
	while(r > l + 1)
    {
        int m = (l + r) / 2;
        if(y >= lo[now][m].first)
            l = m;
        else
            r = m;
    }

	cout<<"lst - l = "<<lst - l<<endl;

    return lst - l;
}
int findbigb(int l, int r, int y)
{
    if(y >= b[r].first)
        return 0;
    if(y < b[l].first)
        return r - l + 1;
    int lst = r;

	int p = lower_bound(b+l+1,b+r+1,make_pair(y,1))-b;
	cout<<"lst - p = "<<lst - p<<endl;
	while(r > l + 1)
    {
        int m = (l + r) / 2;
        if(y >= b[m].first)
            l = m;
        else
            r = m;
    }


	cout<<"lst - l = "<<lst - l<<endl;
    return lst - l;
}
int main()
{
	long beginTime =clock();//获得开始时间，单位为毫秒
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t;
    // scanf("%d", &t);
	t = getint();
    while(t--)
    {
        // scanf("%d%d", &n, &m);
		n = getint();
		m = getint();

        len = 0;
        memset(s, 0, sizeof s);
        row(i, 1, n)
        {
            // scanf("%d", &a[i]);
        	//cin >> a[i];
			a[i] = getint();
            if(a[i] > b[len].first)
            {
                b[++len].first = a[i];
                b[len].second = i;
                s[i] = len;
                lo[len].clear();
            }
        }
        b[len + 1].first = 1e9 + 7;
        b[len + 1].second = n + 1;

		row(i, 1, len)
        {
            lo[i].push_back(b[i - 1]);
            row(j, b[i].second + 1, b[i + 1].second - 1)
                if(a[j] > lo[i][lo[i].size() - 1].first)
                    lo[i].push_back(make_pair(a[j], j));
        }

        row(i, 1, m)
        {
            int x, y;
            // scanf("%d%d", &x, &y);
			x = getint();
			y = getint();
            //cin >> x >> y;
            if(a[x] == y)
            {
                cout << len << endl;
                continue;
            }
            if(a[x] > y)   //改小
            {
                if(s[x])  // 在队列中
                {
                    int now = s[x];
                    if(y <= b[now- 1].first)  // 如果已经比上一个还小了
                    {
                        cout << len + lo[now].size() - 2 << endl;
                        continue;
                    }
                    else
                    {
                        cout << len + findbig(now, 1, lo[now].size() - 1, y) << endl;
                        continue;
                    }
                }
                else  // 不在一定不用
                {
                    cout << len << endl;
                    continue;
                }
            }
            else        // 改大
            {
                if(s[x])
                {
                    int now = s[x];
                    cout << now + findbigb(now + 1, len, y) << endl;
                    continue;
                }
                else
                {
                    int now = findstrg(x);
                    if(y <= b[now].first || y == b[now + 1].first)
                    {
                        cout << len << endl;
                        continue;
                    }
                    else if(y > b[now].first && y < b[now + 1].first)
                    {
                        cout << len + 1 << endl;
                        continue;
                    }
                    else
                    {
                        cout << now + 1 + findbigb(now + 2, len, y) << endl;
                        continue ;
                    }
                }
            }
        }
    }
	long endTime=clock();//获得结束时
	// cout<<endTime - beginTime<<endl;
	// cout<<"????"<<endl;
    return 0;
}
5
6 5
10 2 3 40 7 60
2 12
2 1
2 3
