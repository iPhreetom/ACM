// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;

	int tot = (m-1)*m/2;
	int sum = 0; //  actually length
	string ans;
	deque<unordered_map<char,int>> que[11];
	int cnt[11];
	memset(cnt,0,sizeof(cnt));

	while(tot--) {
		string s;int num;
		cin >> s >> num;
		if (num == 0) continue;

		for (int i=0; i<s.size(); i++){
			unordered_map<char,int> mp;
			if (que[s[i]-'a'].empty(mp)) {
				
			}
			else {

			}
		}
	}
	return 0;
}
