#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll x,y,n;
	string s;
	cin>>n>>x>>y;
	cin>>s;

	ll ans = 0;
	bool wait = 0;
	if(x < y){
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				for(int j=i;j<=s.size();j++){
					if(j == s.size()){
						ans+=y;
						cout<<ans<<endl;
						return 0;
					}

					if(s[j] == '1'){
						i = j-1;
						ans += x;
						wait = 1;
						break;
					}
				}
			}
		}
		if(wait == 1 && s[s.size()-1] == '1'){
			ans += y;
		}
	}
	else{
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				for(int j=i;j<=s.size();j++){
					if(j == s.size()){
						ans+=y;
						cout<<ans<<endl;
						return 0;
					}

					if(s[j] == '1'){
						i = j-1;
						ans += y;
						break;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
