// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
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

bool findnum(string &a,string &b){
	getFail(b);
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
	string a,b;
	int n,m;
	cin>>n>>m;
	cin>>a>>b;

	for (int i=0; i<n; i++){
		if(a[i] == '*'){
			string lf,rt;
			lf = a.substr(0,i);
			rt = a.substr(i+1);
			int index ;
			string L,R;


			if(findnum(b,rt) && findnum(b,lf)){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}

			return 0;
		}
	}

	if(findnum(b,a)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}
