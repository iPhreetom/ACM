// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<string> lis;
	vector<int> val;
	string now;
	for (int i=0; i<s.size(); i++){
		if ('0' <= s[i] && s[i] <= '9') {
			int index = i;
			string temp;
			for (int j=i; j<s.size(); j++,index++){
				if ('0' <= s[j] && s[j] <= '9') temp.push_back(s[j]);
				else break;
			}
			lis.push_back(now);
			now.clear();
			val.push_back(atoi(temp.c_str()));
			i = index-1;
		}
		else now.push_back(s[i]);
	}
	lis.push_back(now);
	val.push_back(0);

	while (n--) {
		string t;
		cin >> t;
		if (t == s) {cout << "+\n"; continue;}

		vector<string> list;
		vector<int> valt;
		string now;
		for (int i=0; i<t.size(); i++){
			if ('0' <= t[i] && t[i] <= '9') {
				int index = i;
				string temp;
				for (int j=i; j<t.size(); j++,index++){
					if ('0' <= t[j] && t[j] <= '9') temp.push_back(t[j]);
					else break;
				}
				list.push_back(now);
				now.clear();
				valt.push_back(atoi(temp.c_str()));
				i = index-1;
			}
			else now.push_back(t[i]);
		}
		list.push_back(now);
		valt.push_back(0);

		bool sm = 1;
		bool out = 0;
		for (int i=0; i<lis.size() && i<list.size(); i++){
			if (lis[i] != list[i]) {
				
			}
			else {

			}
		}
	}
	return 0;
}
