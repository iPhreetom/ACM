// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
using namespace std;

int a[11223];

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

inline int findnum(string &a,string &b){
	int j = 0;
	int ans = 0;
	for (int i=0; i<a.size(); i++){
		while(j && b[j] != a[i])j = f[j];
		if(b[j] == a[i])j++;
		if(j == b.size())ans++;//find one
	}
	return ans;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	string c = "01100001";

	int ans = 0;
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	for (int i=0; i<n; i++){
		string b;
		b.clear();
		for (int j=0; j<32; j++){
			if(a[i]%2 == 1)b.push_back('1');
			else b.push_back('0');
			a[i]/=2;
		}
		reverse(b.begin(),b.end());
		for (int j=0; j<32; j+=8){
			bool ok = 1;
			for(int k=0;k<8;k++){
				if(c[k] != b[j+k])ok = 0;
			}
			if(ok)ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
