// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


bool vis[5][5];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	int index = 1;
	int index2 = 1;
	for (int i=0; i<s.size(); i++){
		if(s[i] == '0') {
			if(index == 0) index = 1;
			if(index == 1) {
				cout<<1<<' '<<1<<endl;
			}
			if(index == 2) {
				cout<<1<<' '<<2<<endl;
			}
			if(index == 3) {
				cout<<1<<' '<<3<<endl;
			}
			if(index == 4) {
				cout<<1<<' '<<4<<endl;
			}
			index++;
			index %= 5;
		}
		else {
			if(index2 == 0) index2 = 1;
			if(index2 == 1) {
				cout<<3<<' '<<1<<endl;
			}
			if(index2 == 2) {
				cout<<3<<' '<<3<<endl;
			}
			if(index2 == 3) {
				cout<<4<<' '<<1<<endl;
			}
			if(index2 == 4) {
				cout<<4<<' '<<3<<endl;
			}
			index2++;
			index2 %= 5;
		}
	}
	return 0;
}
