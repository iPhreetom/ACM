#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a;
	string b;
	char c;
	while(cin>>c){
		if(c != '\n' && c!=' '){
			if(c != '-'){
				a.push_back(c);
			}
			b.push_back(c);
		}
	}

	int ans = 0;
	for(int i=0;i<a.size()-1;i++){
		ans += ((i+1) * (a[i]-'0'));
	}

	ans %= 11;
	if(ans == (a[a.size()-1] - '0') || (ans == 10 && a[a.size()-1] == 'X')){
		cout<<"Right"<<endl;
	}
	else{
		for(int i=0;i<b.size()-1;i++){
			cout<<b[i];
		}
		if(ans == 10){
			cout<<'X'<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
}
