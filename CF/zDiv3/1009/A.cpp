#include<bits/stdc++.h>
#define int long long
using namespace std;



vector<int> a,b;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n,m;
	cin>>n>>m;

	int t;
	for(int i=0;i<n;i++){
		cin>>t;
		a.push_back(t);
	}
	for(int i=0;i<m;i++){
		cin>>t;
		b.push_back(t);
	}

	int ans = 0;
	int index = 0;
	for(int i=0;i<a.size();i++){
		if(b[index] >= a[i]){
			index++;
			ans++;
		}
		if(index >= m){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
