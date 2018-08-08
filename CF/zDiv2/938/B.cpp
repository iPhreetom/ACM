#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;



double a[212345];
double b[212345];
double sum;
double jidian ;
int ans =  0;
int n;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t1,t2;
	// cout<<(-134)%10<<endl;
	cin>>t1>>t2;

	bool fu = 0;
	unsigned int ans ;
	if(t1 < 0 && t2 > 0){
		fu = 1;
		ans = ((unsigned int)abs(t2)) + abs(t1);
	}
	else if(t1 > 0 && t2 < 0){
		fu = 0;
		ans = ((unsigned int)abs(t2)) + abs(t1);
	}else if(t1 < t2){
		fu = 1;
		ans = abs(t1-t2);
	}else{
		ans = abs(t1-t2);
	}


	string s;
	if(ans == 0){
		cout<<0<<endl;
		return 0;
	}

	int cnt=0;
	while(ans){
		cnt++;
		s.push_back((ans%10+'0'));
		ans/=10;
		if(cnt % 3 == 0 && ans){
			s.push_back(',');
		}
	}

	if(fu){
		cout<<'-';
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
	return 0;
}
