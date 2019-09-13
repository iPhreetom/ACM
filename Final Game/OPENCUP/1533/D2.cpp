// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int vals[41234];
int valt[41234];
int alls;
int allt;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s, t;
	cin >> s >> t;
	string strs = "#"+s;
	string strt = "#"+t;

	for (int i=1; i<strs.size(); i++){
		if (strs[i]!=strs[i-1]) {
			alls++;
			strs[i-1] = alls;
		}
	}
	for (int i=1; i<strt.size(); i++){
		if (strt[i]!=strt[i-1]) {
			allt++;
			strt[i-1] = allt;
		}
	}
	for (int i=0; i<s.size(); i++){
		strs[i] = alls-strs[i];
	}
	for (int i=0; i<t.size(); i++){
		strt[i] = allt-strt[i];
	}

	int indexs = 0,indext = 0;
	string ans;
	int mx = 0;

	while(indexs<s.size() || indext<t.size()) {
		int ss = -1;
		int st = -1;
		if (indexs<s.size()) {
			ss = s[indexs]-'0';
		}
		if (indext<t.size()){
			st = t[indext]-'0';
		}

		if (ss==st) {
			ans.push_back(!ss+'0');
			while(indexs<s.size() && s[indexs]=='0'+ss) indexs++;
			indexs++;
			while(indext<t.size() && t[indext]=='0'+st) indext++;
			indext++;
		}
		else if(ss == -1){
			ans.push_back(!st+'0');
			while(indext<t.size() && t[indext]=='0'+st) indext++;
			indext++;
		}
		else if(st == -1){
			ans.push_back(!ss+'0');
			while(indexs<s.size() && s[indexs]=='0'+ss) indexs++;
			indexs++;
		}
		else if(st != ss) {
			if (ss == 0) { // st == 1
				if ()
				indexs++;
				while (indext<t.size() && t[indext]=='0'+st) indext++;
				indext++;
			}
			else { // st == '0'
				indext++;
				while (indexs<s.size() && s[indexs]=='0'+ss) indexs++;
				indexs++;
			}
		}

		cout<<"indexs = "<<indexs<<endl;
		cout<<"indext = "<<indext<<endl;
		cout<<"ss = "<<ss<<endl;
		cout<<"st = "<<st<<endl;
		cout<<"ans = "<<ans<<endl;
	}

	cout << ans << endl;
	return 0;
}
