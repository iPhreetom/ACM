// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	string s1, s2;

	cin>>n;
	cin >> s1 >> s2;

	bool con = 0;
	int cnt1 = 0;
	int cnt2 = 0;

	for (int i=0; i<s1.size(); i++){
		if(s1[i] == '1' && s1[i] == s2[i]) {
			con ^= 1;
		}
		if(s1[i] == '1')cnt1 ++ ;
		if(s2[i] == '1')cnt2 ++ ;
	}

	if(cnt1 > cnt2) {
		cout<<"First"<<endl;
	}
	else if(cnt1 == cnt2) {
		if(con){
			cout<<"First"<<endl;
		}
		else{
			cout<<"Draw"<<endl;
		}
	}
	else if(cnt1 < cnt2) {
		if( (cnt2 == cnt1 + 1) || ((cnt2 == cnt1 +2) && con)){
			cout<<"Draw"<<endl;
		}
		else{
			cout<<"Second"<<endl;
		}
	}

	return 0;
}
