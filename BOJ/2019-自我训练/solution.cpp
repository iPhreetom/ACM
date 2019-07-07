// fyt
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_set<string> s;
	for (int i=0; i<n; i++){
		string str;
		cin >> str;
		s.insert(str);
	}
	for (int i=0; i<m; i++){
		string str;
		cin >> str;
		if (s.find(str) != s.end()) {
			s.erase(str);
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
