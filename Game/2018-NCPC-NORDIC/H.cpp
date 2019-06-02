// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int toint (string &s) {
	int ret = 0;
	int len = s.size()-1;
	for (int i=0; i<s.size(); i++){
		ret += (s[i]-'0')*pow(10,len);
		len--;
	}
	return ret;
}

signed main(){
	int n,m;
	int t = 10080;
	typedef pair<pair<int,int>,string> pii;
	priority_queue<pii,vector<pii>,greater<pii>> que;
	cin >> n >> m;
	string s;
	getline(cin, s);
	for (int j=1; j<=m; j++) {
		getline(cin, s);
		s.push_back(',');
		string name;
		vector<int> v;
		string tmp;
		for (int i=0; i<s.size(); i++){
			if (s[i] == ',') {
				if (name.empty()) name = tmp;
				else v.push_back(toint(tmp));
				tmp.clear();
			}
			else {
				tmp.push_back(s[i]);
			}
		}
		int ci = 1008000000*t/(v[3] + v[2]);
		int deal = ci*v[1]*v[2] + min(1008000000*t-ci*(v[3]+v[2]),v[2])*v[1];
		if (deal >= 1008000000*n) {
			que.push(make_pair(make_pair(v[0],j),name));
		}
		s.clear();
	}

	if (que.empty()){
		cout << "no such mower" << endl;
	}
	else {
		int mn = que.top().first.first;
		while(!que.empty() && que.top().first.first == mn) {
			cout << que.top().second << endl;
			que.pop();
		}
	}
 	return 0;
}
