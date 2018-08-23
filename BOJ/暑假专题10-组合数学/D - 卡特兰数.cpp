#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;



int f[1123456];
int nf[1123456];
int mod = 1000000007;

int exgcd(int a,int b,int &x,int &y){
    int result = a;
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        result = exgcd(b,a%b,y,x);
        y -= (a/b)*x;
    }
    return result;
}


void init(){
	f[0]=1;
	f[1]=1;
	nf[1]=1;
	int x,y;
	for (int i=2; i<=1123455; i++){
	    f[i] = (f[i-1]*i)%mod;
		exgcd(f[i],mod,x,y);
		nf[i] = (x+mod)%mod;
	}
}

int c(int r,int l){
	if(l == 0)return 1;
	return f[r]*nf[r-l]%mod*nf[l]%mod;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init();
	int n;string s;
	while(cin>>n>>s){
		int l = 0;
		int r = 0;
		int nl=n/2;
		int nr=n/2;
		bool ok = 1;
		if(n % 2 == 1)ok = 0;
		for (int i=0; i<s.size(); i++){
			if(s[i]=='('){l++;nl--;r++;}
			else {l--;nr--;}
			if(l < 0)ok = 0;
		}
		if(r > n/2)ok = 0;
		l = nl;
		r = nr;

		if(!ok){
			cout<<0<<endl;
		}
		else{
			if(l == 0 || r == 0){
				if(r+l == 0){
					cout<<1<<endl;
				}
				else{
					cout<<1<<endl;
				}
			}
			else cout<<(c(r+l,l)-c(r+l,l-1) + mod)%mod<<endl;
		}
	}
	return 0;
}
