// fyt
#include<bits/stdc++.h>
#define double long double
using namespace std;

queue<int> que;
int ans[255];
multiset<int> s[255];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	int q = tt;
	while(tt--){
		int n,m;
		for (int i=0; i<205; i++){
		    s[i].clear();
		}
		while(!que.empty())que.pop();

		cin>>n>>m;
		for (int i=0; i<m; i++){
			int t;cin>>t;
			if(t == 1)t+=13;
			if(t == 2)t+=13;
			que.push(t);
		}

		bool win = 0;
		for (int i=1; i<=n; i++){
		    for (int j=0; j<5 && !que.empty(); j++){
		        s[i].insert(que.front());
				que.pop();
		    }
		}

		int last = 0;
		int cnt = 0;
		while(!win){
			// cout<<last<
			for (int i=1; i<=n && !win; i++){
				if(last == 0){
					cnt=0;
					last = *s[i].begin();
					s[i].erase(s[i].find(*s[i].begin()));
				}
				else{
					if(s[i].count(last+1) == 0){
						if(last != 15 && s[i].count(15) != 0){
							last = 15;
							cnt = 0;
							s[i].erase(s[i].find(15));
						}
						else{
							cnt++;
						}
					}
					else{
						s[i].erase(s[i].find(last+1));
						last = last + 1;
						cnt = 0;
					}
				}

				if(s[i].size() == 0){
					win = 1;
					break;
				}

				if(cnt == n-1){
					for (int j=1;!que.empty() && j<=n; j++){
						int p = (i+j);
						if(p > n)p-=n;
						s[p].insert(que.front());
						que.pop();
					}
					last = 0;
					cnt = 0;
				}
			}
		}
		for (int i=1; i<=n; i++){
			ans[i] = 0;
			for(auto j : s[i]){
				if(j == 15 || j == 14)j-=13;
			    ans[i] += j;
			}
		}
		cout<<"Case #"<<q-tt<<":"<<endl;
		for (int i=1; i<=n; i++){
		    if(ans[i] == 0){
				cout<<"Winner"<<endl;
			}
			else{
				cout<<ans[i]<<endl;
			}
		}
	}
	// 1 2 8 1 1 2 2 2 2 2 5
	return 0;
}
