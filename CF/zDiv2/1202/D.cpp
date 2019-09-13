// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string ans;

void dfs(int n) {
	int lt=2,rt=1;
	while((lt)*(lt-1)/2*rt < n) {
		if ((lt+1)*(lt)/2*rt <= n) lt++;
		else if ((lt)*(lt-1)/2*(rt+1) <= n) rt++;
		else break;
	}
	if (ans.empty()) ans.push_back('1');
	for (int i=1; i<=lt; i++){
		ans.push_back('3');
	}
	for (int j=0; j<rt; j++){
		ans.push_back('7');
	}
	if ((lt)*(lt-1)/2*rt != n) {
		n -= (lt)*(lt-1)/2*rt;
		dfs(n);
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ans.clear();
		dfs(n);
		cout << ans << endl;
		// cout<<"ans.size() = "<<ans.size()<<endl;
	}
	return 0;
}
