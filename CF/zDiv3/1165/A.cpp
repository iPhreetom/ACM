// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,x,y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	reverse(s.begin(),s.end());
	int ans = 0;
	for (int i=0; i<y; i++){
		if (s[i] == '1')ans++;
	}
	if (s[y] == '0') ans++;
	for (int i=y+1; i<x; i++){
		if (s[i] == '1')ans++;
	}
	cout << ans << endl;
	return 0;
}
