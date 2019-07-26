// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


char mp[150][150];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0) ,cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		for (int i=0; i<150; i++){
			for (int j=0; j<150; j++){
				mp[i][j] = '.';
			}
		}
		int a, b, c;
		cin >> a >> b >> c;
		int height = c*2+1+2*b;
		int width = a*2+1+b*2;

		// line
		int space = b*2;
		int len = a*2+1;
		for (int i=0; i<=space; i+=2){
			bool f=1;
			for (int j=space-i; j<space-i+len; j++){
				mp[i][j] = (f==1)?'+':'-';
				f = !f;
			}
		}
		for (int i=space+2; i<c*2+1+2*b; i+=2) {
			bool f=1;
			for (int j=0; j<a*2+1; j++){
				mp[i][j] = (f==1)?'+':'-';
				f = !f;
			}
		}

		// '/'
		for (int i=1; i<=space; i+=2){
			bool f=1;
			for (int j=space-i; j<space-i+a*2+1; j+=2){
				mp[i][j] = '/';
			}
		}
		int cnt = b*2;
		int be = 1;
		for (int j=width-1-1; j>=(width-b*2); j-=2) {
			for (int i=be; i<be+c*2+1; i+=2){
				mp[i][j] = '/';
			}
			cnt-=2;
			be+=2;
		}

		// '| and +' pilliar
		for (int i=space+1; i<height; i+=2){
			for (int j=0; j<a*2+1; j+=2){
				mp[i][j] = '|';
			}
		}
		len = c*2+1;
		cnt = 0;
		for (int j=width-1; j>=(width-b*2); j-=2) {
			bool f = 1;
			for (int i=cnt; i<cnt+len; i++){
				mp[i][j] = (f==1)?'+':'|';
				f = !f;
			}
			cnt+=2;
		}

		// output
		for (int i=0; i<height; i++){
			for (int j=0; j<width; j++){
				cout << mp[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
