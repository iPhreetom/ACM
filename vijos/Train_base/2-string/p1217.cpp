#include<bits/stdc++.h>
#define int long long
using namespace std;




int w,l;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	string a;
	while(cin>>a){
		s = s+a;
	}

	int cnt=0;

	for(int i=0;i<s.size();i++){
		cnt++;
		if(s[i]=='W'){
			w++;
		}
		else if(s[i]=='L'){
			l++;
		}
		else{
				cout<<w<<':'<<l<<'\n';
				break;

		}
		if((w >= 11 || l >= 11) && abs(w-l)>=2){
			cout<<w<<':'<<l<<'\n';
			cnt=0;
			w=0;
			l=0;
		}
	}
	cout<<endl;

	l=0,w=0;
	for(int i=0;i<s.size();i++){
		cnt++;
		if(s[i]=='W'){
			w++;
		}
		else if(s[i]=='L'){
			l++;
		}
		else{
			// if(w == 0 && l == 0)break;

			cout<<w<<':'<<l<<'\n';
			break;

		}
		if((w >= 21 || l >= 21) && abs(w-l)>=2){
			cout<<w<<':'<<l<<'\n';
			cnt=0;
			w=0;
			l=0;
		}
	}
	return 0;
}
