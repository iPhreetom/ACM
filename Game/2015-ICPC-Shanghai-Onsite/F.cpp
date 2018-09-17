// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int nn;
	cin>>nn;
	for(int tt=1;tt<=nn;tt++){
		int mn[27];
		int last[27];
		for (int i=0; i<27; i++){
		    last[i] = -100000;
		}
		string s;

		memset(mn,0x3f,sizeof(mn));
		cin>>s;
		for (int i=0; i<s.size(); i++){
			mn[s[i]-'a'] = min(mn[s[i]-'a'],i-last[s[i]-'a']);
			last[s[i]-'a'] = i;
		}
		int ans = 100000;
		for (int i=0; i<27; i++){
		    ans = min(ans,mn[i]);
		}
		cout<<"Case #"<<tt<<": ";
		if(ans > 1000){
			cout<<-1<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
}
