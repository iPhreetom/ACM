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
//x+mt=y+nt(mod l)
//(m-n)t=y-x(mod l)
//(m-n)t+ls=y-x (t->要求的解(x) s->y)
//若gcd(m-n,l)|y-x不满足则impossible
ll gcd(ll a,ll b)
{
  if(a<b)swap(a,b);
  return b==0?a:gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
  if(b==0)
  {
    x=1;y=0;
    return a;
  }
  ll d=exgcd(b,a%b,x,y);
  int z=x;x=y;y=z-(y*(a/b));
  return d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
  ll x,y,m,n,l,t,s,d;
  cin>>x>>y>>m>>n>>l;
  if(m<n)
  {
    swap(m,n);
    swap(x,y);
  }
  if(y<x)y+=l;
  if((y-x)%gcd(m-n,l))
  {
    cout<<"Impossible\n";
    return 0;
  }
  d=exgcd((m-n),l,t,s);
  t*=(y-x)/d;
  //cout<<d<<" "<<t<<endl;
  while(t<0)t+=l/d;
  t%=l/d;
  if(!t)t+=l/d;
  cout<<t<<endl;
	return 0;
}
