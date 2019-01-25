// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int low[2123456];
int one[2123456];
int two[2123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int x;
	cin >> x;

	for (int i=1; i<=2123455; i++){
		one[i] = i + one[i-1];
		two[i] = one[i-1] + two[i-1];
		low[i] = one[i]*i - two[i];
		if(low[i] >= 1e18)break;
	}

	vector<int> ans1;
	vector<int> ans2;

	for (int i=1; i<=2123455; i++){
		if(x >= low[i]) {
			int val = x+two[i];
			if(val % one[i] == 0) {
				ans1.push_back(i);
				ans2.push_back(val/one[i]);
			}
		}
		else break;
	}

	if(ans1.empty()){
		cout<<0<<endl;
		return 0;
	}
	if(ans1.back() != ans2.back()) {
		cout<<ans1.size()*2<<endl;s
		for (int i=0; i<ans1.size(); i++){
			cout<<ans1[i]<< ' ' << ans2[i]<<endl;
		}
		for (int i=ans1.size()-1; i>=0; i--){
			cout<<ans2[i]<< ' ' << ans1[i]<<endl;
		}
	}
	else{
		cout<<ans1.size()*2 - 1<<endl;
		for (int i=0; i<ans1.size(); i++){
			cout<<ans1[i]<< ' ' << ans2[i]<<endl;
		}
		ans1.pop_back();
		ans2.pop_back();
		for (int i=((long long)ans1.size())-1; i>=0; i--){
			cout<<ans2[i]<< ' ' << ans1[i]<<endl;
		}
	}
	return 0;
}
