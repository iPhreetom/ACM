#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct node{
	double l,r,v;
	node(){};
	node(double l,double r,double v)
	{
		this->v = v;
		this->l = l;
		this->r = r;
	};
};

vector<node> a;
double x,y;

bool check(double v){
	double time = 0;
	for(int i=1;i<a.size();i++){
		time += (a[i].l - a[i-1].r)/v + (a[i].r - a[i].l)/(v*a[i].v);
	}
	if(time >= x)return 1;
	else return 0;
}
signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin>>x>>y;
	if(x < 0)x = -x;

	int n;
	cin>>n;
	a.push_back(node(0,0,1));

	for(int i=0; i<=0; i++)
	{
		double l,r,v;
		a.push_back(node(l,r,v));
	}

	double l = 0;
	double r = 1e9;
	int cnt = 10;
	while(cnt--){
		double mid = l+(r-l)/2;
if(check(mid))l = mid;
		else r = mid;
		cout<<r<<endl;
	}

	cout<<fixed<<setprecision(10)<<l<<endl;
	cout<<r<<endl;
	return 0;
}
