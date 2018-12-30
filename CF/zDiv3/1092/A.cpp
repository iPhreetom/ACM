// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string ans;
		int cnt = 0;
		int index = 0;
		for (int i=1; i<=n; i++){
			++cnt;
			if(cnt == n/k){
				cnt = 0;
				ans.push_back(index+'a');
				if(index < k-1)index++;
			}
			else{
				ans.push_back(index+'a');
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
