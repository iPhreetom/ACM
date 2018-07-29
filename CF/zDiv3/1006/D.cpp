#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
string a,b;
int ans = 0;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);


	cin>>n;
	cin>>a>>b;

	//
	for(int i=0;i<(n+1)/2;i++){
		if(n%2==1 && i==((n+1)/2)-1){
			if(a[i] != b[i])ans++;
		}
		else{
			map<char,int> mp;
			mp[a[i]]++;
			mp[b[i]]++;
			mp[a[n-1-i]]++;
			mp[b[n-1-i]]++;
			if(mp.size() != 1){
				if(mp.size() == 4){
					ans += 2;
				}
				else if(mp.size() == 3){
					if((a[i] != b[n-1-i] && a[i] != b[i]) && (a[n-1-i] != b[n-1-i] && a[n-1-i] != b[i]) && (b[i] != b[n-1-i]))ans+=2;
					else ans++;
				}
				else if(mp.size() == 2){
					if(mp.begin()->second == 1 || mp.begin()->second == 3){
						ans++;
					}
				}
			}
		}

	}
	cout<<ans<<endl;
	return 0;
}
