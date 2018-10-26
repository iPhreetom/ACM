// fyt
#include<bits/stdc++.h>
#define double long double
#define endl '\n'
using namespace std;

map<string,pair<int,string>> mp;

void get_sub(string &s){
	set<string> st;
	for (int i=0; i<s.size(); i++){
	    for (int j=i+1; j<=s.size(); j++){
			st.insert(s.substr(i,j-i));
	    }
	}
	for(auto &i:st){
		mp[i].first += 1;
		if(mp[i].first == 1){
			mp[i].second = s;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		string s;
		cin>>s;
		get_sub(s);
	}

	int m;
	cin>>m;
	for (int i=0; i<m; i++){
	    string s;
		cin>>s;
		if(mp[s].first == 0){
			cout<<mp[s].first<<' '<<'-'<<endl;
		}
		else{
			cout<<mp[s].first<<' '<<mp[s].second<<endl;
		}
	}
	return 0;
}
