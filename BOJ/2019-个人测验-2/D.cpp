// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

map<pair<pair<int,int>,pair<int,int>>,set<char>> mp;

void freehash(string &a){
	int seed = 1000543273;
	int seed2 = 131313131;

	int seedd = 1600051751;
	int seedd2 = 1600135819;

	int num = 0;
	int num2 = 0;
	vector<int> re(a.size());
	vector<int> re2(a.size());

	for (int i=0; i<a.size(); i++){
	    num = num*seed + a[i];
		num %= 1304461099;
		re[i] = num;

		num2 = num2*seed2 + a[i];
		num2 %= 1600316759;
		re2[i] = num2;
	}

	num = 0;
	num2 = 0;
	for (int i=a.size()-1; i>=0; i--){
		if(i != 0) {
			mp[make_pair(make_pair(re[i-1],re2[i-1]),make_pair(num,num2))].insert(a[i]);
		}
		else {
			mp[make_pair(make_pair(0ll,0ll),make_pair(num,num2))].insert(a[i]);
		}

	    num2 = num2*seedd2 + a[i];
		num2 %= 1304461099;

		num = num*seedd + a[i];
		num %= 1600457879;
	}
}

bool freehash2(string &a){
	int seed = 1000543273;
	int seed2 = 131313131;

	int seedd = 1600051751;
	int seedd2 = 1600135819;

	int num = 0;
	int num2 = 0;
	vector<int> re(a.size());
	vector<int> re2(a.size());

	for (int i=0; i<a.size(); i++){
	    num = num*seed + a[i];
		num %= 1304461099;
		re[i] = num;

		num2 = num2*seed2 + a[i];
		num2 %= 1600316759;
		re2[i] = num2;
	}

	num = 0;
	num2 = 0;
	for (int i=a.size()-1; i>=0; i--){
		if(i != 0) {
			if(mp.count(make_pair(make_pair(re[i-1],re2[i-1]),make_pair(num,num2))) != 0) {
				if (mp[make_pair(make_pair(re[i-1],re2[i-1]),make_pair(num,num2))].count(a[i]) == 0) return 1;
				else if(mp[make_pair(make_pair(re[i-1],re2[i-1]),make_pair(num,num2))].size() > 1) return 1;
			}
		}
		else {
			if(mp.count(make_pair(make_pair(0ll,0ll),make_pair(num,num2))) != 0) {
				if (mp[make_pair(make_pair(0ll,0ll),make_pair(num,num2))].count(a[i]) == 0) return 1;
				else if(mp[make_pair(make_pair(0ll,0ll),make_pair(num,num2))].size() > 1) return 1;
			}
		}

	    num2 = num2*seedd2 + a[i];
		num2 %= 1304461099;

		num = num*seedd + a[i];
		num %= 1600457879;
	}
	return 0;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;

	string s;
	for (int i=0; i<n; i++){
		cin >> s;
		freehash(s);
	}

	while (m--) {
		string t;
		cin >> t;
		if(freehash2(t)){
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
