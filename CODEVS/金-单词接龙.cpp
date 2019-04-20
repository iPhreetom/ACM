// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int ans = 0;
vector<string> mp;
void dfs(string ch, int len, vector<int> &v) {
	ans = max(ans,len);
	for (int i=0; i<mp.size(); i++){
		for (int j=1; j<=(int)min(mp[i].size(),ch.size())-1; j++){
			string a = mp[i].substr(0,j);
			string b = ch.substr((int)ch.size()-j);
			if(a == b && v[i] < 2) {
				v[i]++;
				// cout<<"add = "<<mp[i]<<endl;
				dfs(mp[i],len+(mp[i].size()-j),v);
				// cout<<"delete = "<<mp[i]<<endl;
				v[i]--;
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n; cin >> n;
	mp.resize(n);
	for (int i=0; i<mp.size(); i++){
	    cin >> mp[i];
	}
	string ch;
	cin >> ch;
	ch = "#" + ch;
	vector<int> v(n,0);


	dfs(ch,1,v);
	cout << ans << endl;
	return 0;
}
// ababa
// ab
//  ba
//   ab
//    ba
