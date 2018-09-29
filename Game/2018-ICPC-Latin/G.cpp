// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


struct node{
	int x=0,y=0,f=0,s=0;
	node() = default;
	node(int x,int y ,int f){
		this->x = x;
		this->f = f;
		this->y = y;
		this->s = 0;
	}
};

node a[112345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++){
		int x,y,f;
		cin>>x>>y>>f;
		a[i] = node(x,y,f);
	}
	return 0;
}
