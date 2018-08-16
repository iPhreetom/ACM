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
typedef long long ll;
const int maxn=1e5+5;
struct rec
{
	int id;
	ll len;
}a[maxn],t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
  int n;
  while(cin>>n&&n)
  {
    stack<rec>s;//单调递减栈
    for(int i=1;i<=n;i++)cin>>a[i].len,a[i].id=i;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
      if(s.empty())
			{
				s.push(a[i]);
				continue;
			}
			while((!s.empty())&&s.top().len>a[i].len)
			{
				t=s.top();s.pop();
				int j=(s.empty())?(0):(s.top().id);
				ll cur=t.len*(i-j-1);
				if(cur>ans)
				{
					ans=cur;
				}
			}
			s.push(a[i]);
    }
		ll l1=1,r1=n;
		while(!s.empty())
		{
			t=s.top();s.pop();
			l1=(s.empty())?(0):(s.top().id);
			ll cur=(r1-l1)*t.len;
			if(cur>ans)
			{
				ans=cur;
			}
		}
		cout<<ans<<endl;
  }
	return 0;
}
