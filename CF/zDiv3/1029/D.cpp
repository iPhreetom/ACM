// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

map<int,int> mp[11];
pair<int,int> a[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=0; i<n; i++){
		int q;cin>>q;
		int t = q;
		int len = 0;
		while(t>0){
			t/=10;
			len++;
		}
		a[i] = make_pair(q,len);
		mp[len][q%k]++;
	}
	int ans = 0;
	for (int i=0; i<n; i++){
	    int re = a[i].first % k;
		int c = re;
		for (int j=1; j<=10; j++){
			re *= 10;
			re %= k;
			if(re == 0)re = k;
			if(mp[j].count(k-re) != 0){
				ans+=mp[j][k-re];
				if(j == a[i].second && re + c == k)ans--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
