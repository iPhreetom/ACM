#include<bits/stdc++.h>
#define int long long
using namespace std;


set<int> s;
vector<int> a;
map<int,int> mp;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	int t;
	for(int i=0;i<n;i++){
		cin>>t;
		a.push_back(t);
		s.insert(t);
		mp[t]++;
	}

	int ans = n;
	for(int i=0;i<n;i++){
		for(int j=1;j<=63;j++){
			if(s.count(pow(2,j)-a[i])!=0){
				if(pow(2,j)-a[i] == a[i]){
					if(mp[a[i]]>1){
						ans--;
						break;
					}
				}
				else{
					ans--;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}
