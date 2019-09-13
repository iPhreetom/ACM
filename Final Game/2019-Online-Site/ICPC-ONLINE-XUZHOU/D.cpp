// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> f;
void getFail(string &p){
	f.resize(p.size()+1);
	f[0] = 0;
	f[1] = 0;
	for (int i=1; i<p.size(); i++) {
	    int j = f[i];
		while( j && p[i]!=p[j] )j = f[j];
		f[i+1] = p[i] == p[j]? j+1 : 0;
	}
}

int findnum(string &a,string &b){
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
	string t;
	cin >> t;
	int q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		if (s.size() == t.size()) {
			if (s == t) {
				cout << "jntm!" << endl;
			}
			else {
				cout << "friend!" << endl;
			}
		}
		else if(s.size() > t.size()) {
			if (findnum(s,t) > 0) {
				cout << "my teacher!" << endl;
			}
			else {
				cout << "senior!" << endl;
			}
		}
		else if(s.size() < t.size()) {
			if (findnum(t,s) > 0) {
				cout << "my child!" << endl;
			}
			else {
				cout << "oh, child!" << endl;
			}
		}
	}
	return 0;
}
