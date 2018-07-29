#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x,y,ans;
string s;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>x>>y>>s;


	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='0'&&s[i+1]=='1')ans++;
	}

	if(s[s.size()-1]=='0')ans++;

	if(x >= y){
		ans = y*ans;
		cout<<ans<<endl;
	}
	else{
		if(ans != 0)ans = (ans-1)*x + y;
		cout<<ans<<endl;
	}
	return 0;
}
