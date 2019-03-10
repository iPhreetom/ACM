// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> f;
void getFail(string &p){
	f.resize(p.size()+1);
	f[0] = 0;
	f[1] = 0;
	for (int i=1; i<p.size(); i++){
	    int j = f[i];
		while(j && p[i]!=p[j])j = f[j];
		f[i+1] = p[i] == p[j]? j+1 : 0;
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a,b;
	cin >> a >> b;

	int one = 0;
	int zero = 0;
	for (int i=0; i<a.size(); i++){
		if(a[i] == '1') one++;
		else zero ++;
	}

	int tpa = 0;
	int tpb = 0;
	for (int i=0; i<b.size(); i++){
		if(b[i] == '1') tpa++;
		else tpb++;
	}

	if(tpa > one || tpb > zero) {
		cout << a << endl;
		return 0;
	}



	string ans = b;
	getFail(b);
	int num = f[b.size()];
	string add = b.substr(num);
	int none = 0;
	int nzero = 0;
	for (int i=0; i<add.size(); i++){
		if(add[i] == '1') {
			none++;
		}
		else nzero++;
	}

	// cout<<"one = "<<one<<endl;
	// cout<<"zero = "<<zero<<endl;
	one -= tpa;
	zero -= tpb;

	int rep = min(one/max(1,none), zero/max(1,nzero));
	one -= rep*none;
	zero -= rep*nzero;

	while (rep--) {
		ans += add;
	}

	while(zero > 0) {
		ans += '0';
		zero--;
	}
	while(one > 0){
		ans += '1';
		one--;
	}
	cout << ans << endl;
	return 0;
}
