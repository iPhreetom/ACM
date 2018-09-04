// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> a[212345];
queue<set<int>> que;
bool us[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=0; i<n-1; i++){
	    int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	bool ok = 1;
	set<int> tp;
	for (int i=0; i<a[1].size(); i++){
		tp.insert(a[1][i]);
		us[a[1][i]]=1;
	}
	que.push(tp);

	int index;
	cin>>index;
	if(index != 1)ok=0;
	us[1] = 1;
	for (int d=0; d<n-1; d++){
		cin>>index;
		auto &f = que.front();
		if(f.count(index) == 0){
			ok = 0;
		}
		else{
			f.erase(f.find(index));
			set<int> s;
			for (int i=0; i<a[index].size(); i++){
				if(us[a[index][i]] == 0){
					s.insert(a[index][i]);
					us[a[index][i]] = 1;
				}
			}
			if(!s.empty())que.push(s);
			if(f.empty())que.pop();
		}
	}
	// if(!que.empty()){ok=0;
	// 	auto f = que.front();
	// 	for(auto i:f)cout<<i<<' ';
	// 	cout<<endl;
	// }
	// cout<<que.size()<<endl;
	if(ok){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}
