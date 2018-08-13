// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> f;
void getFail(auto &p){
	f.resize(p.size()+1);
	f[0] = 0;
	f[1] = 0;
	for (int i=1; i<p.size(); i++){
	    int j = f[i];
		while(j && p[i]!=p[j])j = f[j];
		f[i+1] = p[i] == p[j]? j+1 : 0;
	}
}

void findnum(auto &a,auto &b){
	getFail(b);
	int j = 0;
	int ans = 0;
	for (int i=0; i<a.size(); i++){
		while(j && b[j] != a[i])j = f[j];
		if(b[j] == a[i])j++;
		if(j == b.size())ans++;//find one
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	return 0;
}
