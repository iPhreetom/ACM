// kmp 板子题目
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

int findnum(auto &a,auto &b){
	getFail(b);
	int j = 0;
	int ans = 0;
	for (int i=0; i<a.size(); i++){
		while(j && b[j] != a[i])j = f[j];
		if(b[j] == a[i])j++;
		if(j == b.size())return i-j+2;//find one
	}
	return -1;
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		vector<int> a(n, 0);
		vector<int> b(m, 0);
		for (int i=0; i<n; i++) {
		    cin >> a[i];
		}
		for (int i=0; i<m; i++) {
		    cin >> b[i];
		}

		cout << findnum(a,b) << endl;
	}
	return 0;
}
