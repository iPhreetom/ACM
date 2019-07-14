// fyt
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	// unordered_set<string> s;
	unordered_map<string,int> mp;
	for (int i=0; i<n; i++){
		string str;
		cin >> str;
		// s.insert(str);
		mp[str] = 1;
	}
	for (int i=0; i<m; i++){
		string str;
		cin >> str;
		if (mp[str] != 0) {
			mp[str] = 0;
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
