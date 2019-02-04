// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	map<int,int> mp;
	for (int i=0; i<n; i++){
		string s;
		cin>>s;

		int l = 0;
		int r = 0;
		bool can = 1;

		for (int j=0; can && j<s.size(); j++){
			if(s[j] == '('){
				l++;
			}
			else{
				if(l > 0)l--;
				else r++;
			}
		}

		if(l > 0 && r > 0){
			can = 0;
		}

		if(can){
			if(l>0)mp[l] ++;
			else mp[-r] ++;
		}
		// cout<<"l = "<<l<<endl;
	}

	int ans = 0;
	ans += mp[0] / 2;
	for(auto i:mp) {
		int key = i.first;
		int num = i.second;
		if(key>=0)break;
		ans += min(num,mp[-key]);
	}
	cout<<ans<<endl;
	return 0;
}
