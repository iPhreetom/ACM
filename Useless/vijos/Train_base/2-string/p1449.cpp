#include<bits/stdc++.h>
#define int long long
using namespace std;




int n,k;
bool ok;
string a,b,c,ans,tp;
string ta,tb,tc;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// cout<<(-123)%123<<endl;

	cin>>n;
	cin>>a>>b>>c;

	tp = a;
	a = b;
	b = c;
	c = tp;
	ta = a;
	reverse(ta.begin(),ta.end());
	ok = 1;
	for(int i=0;i<n;i++){
		// if(((ta[i]-'a'+1) - (b[i]-'a'+1) - (c[i]-'a'+1))%(ta[i]-'a'+1) != 0)ok=0;
		if(((b[i]-ta[i]) + (c[i]-ta[i]))%26 != 0)ok =0;
	}
	if(ok){
		cout<<ta<<endl;
		return 0;
	}

	tp = a;
	a = b;
	b = c;
	c = tp;
	ta = a;
	reverse(ta.begin(),ta.end());
	ok = 1;
	for(int i=0;i<n;i++){
		if(((b[i]-ta[i]) + (c[i]-ta[i]))%26 != 0)ok =0;
	}
	if(ok){
		cout<<ta<<endl;
		return 0;
	}

	tp = a;
	a = b;
	b = c;
	c = tp;
	ta = a;
	reverse(ta.begin(),ta.end());
	ok = 1;
	for(int i=0;i<n;i++){
		if(((b[i]-ta[i]) + (c[i]-ta[i]))%26 != 0)ok =0;
	}
	if(ok){
		cout<<ta<<endl;
		return 0;
	}
	return 0;
}
