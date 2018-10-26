#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

map<string,vector<string>> mp;
queue<string> que;

inline void solve(string &s){
	s.pop_back();
	string key = "";
	string value = "";
	bool ek = 1;

	for (int i=1; i<s.size(); i++){
		if(s[i] == ':'){
			if(!que.empty()){
				mp[que.back()].push_back(key);
			}

			if(s[i+1] == '{')ek = 1;
			else ek = 0;

			que.push(key);
			key = "";
		}
		else{
			if(ek){
				if(s[i] == '}'){
					mp[key].
					key.push_back(s[i]);
				}
			}

		}
	}
}

inline void query(string &a){

}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		string s;
		cin>>s;
		solve(s);
		int q;
		while(q--){
			string a;
			cin>>a;
			query(a);
		}
	}
	return 0;
}
