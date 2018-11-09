	#include<bits/stdc++.h>
	#define int long long
	#define double long double
	#define endl '\n'
	using namespace std;

	int n,d;
	void solve(string &s){
		queue<int> que[10];
		for (int i=0; i<s.size(); i++){
			que[s[i]-'0'].push(i+1);
		}

		string ans;
		int lt = 0;
		int index=0;
		while(ans.size() < d){
			// cout<<"ans = "<<ans<<endl;
			for (int i=9; i>=0; i--){
				while(!que[i].empty() && (que[i].front() <= lt))que[i].pop();
				if(!que[i].empty()){
					if((n-que[i].front()+1) >= ( d-ans.size() )){
						lt = que[i].front();
						ans.push_back(s[que[i].front()-1]);
						que[i].pop();
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}

	signed main(){
		ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
		string s;
		while(cin>>n>>d)
		{
			if(n==0&&d==0)break;
			cin>>s;
			d = n-d;
			solve(s);
		}
		return 0;
	}
