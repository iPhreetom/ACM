// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	bool line = false;
	while(true){
		int n;
		vector<string> ans;
		cin >> n;
		if (n == 0) break;

		if (!line) line = true;
		else cout << endl;

		for (int i=1000; i<100000; i++) {
			string downs;
			string ups;
			bool vis[10];
			memset(vis,0,sizeof(vis));

			int tp = i;
			while(tp){
				int num = tp%10;
				downs.push_back(num+'0');
				vis[num] = 1;
				tp /= 10;
			}
			if (downs.size()==4) downs.push_back('0'),vis[0]=1;

			int up = i*n;
			if (up >= 100000) continue;
			tp = up;
			while(tp){
				int num = tp%10;
				ups.push_back(num+'0');
				vis[num] = 1;
				tp /= 10;
			}

			int num = 0;
			for (int i=0; i<10; i++){
				num += vis[i];
			}

			// break;
			reverse(ups.begin(),ups.end());
			reverse(downs.begin(),downs.end());
			if (num == 10) {
				ans.push_back(ups+" / "+downs+" = "+to_string(n));
			}
			else continue;

		}

		if (ans.empty()){
			cout << "There are no solutions for "<< n << "."<<endl;
		}
		else {
			for (int i=0; i<ans.size(); i++){
				cout << ans[i] << endl;
			}
		}
	}
	return 0;
}
