// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<pair<int,int>> v;
set<pair<int,int>> s;
int xa,ya;
int xb,yb;
int xc,yc;

void dfsb(int x,int y){
	s.insert(make_pair(x,y));
	if(x == xb && y == yb){
		return ;
	}
	if(x < xb){
		dfsb(x+1,y);
		return ;
	}
	else{
		if(y < yb){
			dfsb(x,y+1);
		}
		else{
			dfsb(x,y-1);
		}
		return ;
	}
}
void dfsc(int x,int y){
	s.insert(make_pair(x,y));
	if(x == xb && y == yb){
		return ;
	}

	if(x > xb){
		dfsc(x-1,y);
		return ;
	}
	else{
		if(y < yb){
			dfsc(x,y+1);
		}
		else{
			dfsc(x,y-1);
		}
		return ;
	}
}

void dfs(){
	xa = v[0].first;
	ya = v[0].second;
	xb = v[1].first;
	yb = v[1].second;
	xc = v[2].first;
	yc = v[2].second;
	dfsb(v[0].first,v[0].second);
	dfsc(v[2].first,v[2].second);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for (int i=1; i<=3; i++){
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	dfs();
	cout<<s.size()<<endl;
	for(auto i:s){
		cout<<i.first<<' '<<i.second<<endl;
	}
	return 0;
}
