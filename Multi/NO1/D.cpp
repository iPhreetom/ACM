#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> a;
map<int,int> mp;
priority_queue<int,vector<int>,greater<int> > que;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	while(n--){
		int n,m;
		int l,r;

		cin>>n>>m;

		a.resize(n);
		mp.clear();

		fill(a.begin(),a.end(),1);
		// 输入
		for(int i=0;i<m;i++){
			cin>>l>>r;
			mp[l] = max(mp[l],r);
		}

		// 开始判断有左端点
		for(int i=0;i<n;i++){
			if(mp.count(i) == 0){
				
			}
		}
	}
	return 0;
}
