#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[212345];
set<int> s;
map<int,int> mp;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int ans = 0;
	int t = 0;
	for(int i=n-1;i>=0;i--){
		t += a[i];
		s.insert(t);
		mp[t] = i;
	}

	t = 0;
	for(int i=0;i<n;i++){
		t += a[i];
		if(s.count(t) != 0){
			if(mp[t] > i){
				ans = t;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}
