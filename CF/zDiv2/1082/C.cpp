// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

priority_queue<int> que[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	set<int> lis;

	cin>>n>>m;
	for (int i=0; i<n; i++){
		int s,r;
		cin>>s>>r;
		que[s].push(r);
		lis.insert(s);
	}

	int p[212345];
	int ans = 0;
	int mx = 0;
	while(!lis.empty()){
		vector<int> del;
		int cnt = 0;
		for(auto i : lis){

			p[i] += que[i].top();
			que[i].pop();

			if(p[i] <= 0){
				del.push_back(i);
			}
			else{
				if(que[i].empty()){
					del.push_back(i);
				}
				cnt += p[i];
			}

		}
		ans = max(ans,cnt);
		for (int i=0; i<del.size(); i++){
			lis.erase(del[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
