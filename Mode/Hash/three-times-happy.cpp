// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct prime{
	bool isprime(int a){
		for (int i=2; i<=sqrt(a); i++){
		    if(a%i == 0)return 0;
		}
		return 1;
	}

	void getprime(){
		int ans = 0;
		for (int i=1e9+3e8; i<2e9; i++){
			if(isprime(i)){ans++;cout<<i<<endl;}
			if(ans == 1313131){
				ans = i;
				break;
			}
		}
		cout<<ans<<endl;
	}
};

int freehash(string &a){
	int seed = 1000543273;
	int num = 0;
	for (int i=0; i<a.size(); i++){
	    num = num*seed + a[i];
		num %= 1304461099;
	}
	return num;
}

int free2hash(string &b){
	int seed = 131313131;
	int num = 0;
	for (int i=0; i<b.size(); i++){
	    num = num*seed + b[i];
		num %= (int)(1e9+7);
	}
	return num;
}

int free3hash(string &b){
	int seed = 10369;
	int num = 0;
	for (int i=0; i<b.size(); i++){
	    num = num*seed + b[i];
		num %= 99581;
	}
	return num;
}

int n;
map<pair<pair<int,int>,int>,int> mp;

bool isprime(int a){
	for (int i=2; i<=sqrt(a); i++){
		if(a%i == 0)return 0;
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	// mp.clear();
	// mp[free2hash(a),free3hash(a) ),freehash(a))]++;
	//
	// for(map<pair<pair<int,int>,int>,int>::iterator i=mp.begin();i!=mp.end();i++){
	// 	mx = max(mx,i->second);
	// }
	int ans = 0;
	for (int i=1e9+6e8; i<2e9; i++){
		if(isprime(i)){ans++;cout<<i<<endl;}
		if(ans == 1313131){
			ans = i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
