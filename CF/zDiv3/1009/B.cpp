#include<bits/stdc++.h>
#define int long long
using namespace std;


string s;
string ans;
int zero=0;
int one=0;
int two=0;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>s;

	for(int i=0;i<s.size();i++){
		if(s[i] == '2'){
			two++;
		}
		if(s[i] == '1'){
			one++;
		}
		if(s[i] == '0'){
			zero++;
		}
	}


	if(two){
		one = 0;
		zero = 0;
		for(int i=s.size()-1;i>=0;i--){
			if(s[i] == '1'){
				one++;
			}
			if(s[i] == '0'){
				zero++;
			}
			if(s[i] == '2'){
				while(zero--){
					ans.push_back('0');
				}
				zero=0;
				ans.push_back('2');
			}
		}

		while(one--){
			ans.push_back('1');
		}
		while(zero--){
			ans.push_back('0');
		}
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
	else{
		while(zero--){
			ans.push_back('0');
		}
		while(one--){
			ans.push_back('1');
		}
		cout<<ans<<endl;
	}
	return 0;
}
