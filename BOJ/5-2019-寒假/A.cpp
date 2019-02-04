#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int sum, k;
	cin >> sum >> k;

	set<int> s;
	vector<pair<int,int>> v;
	for (int i=1; i<=k; i++){
		int t = i;
		int cnt = 0;
		while((t&1) == 0){
			t>>=1;
			cnt++;
		}
		v.push_back(make_pair(pow(2,cnt),i));
	}
	sort(v.begin(),v.end());

	vector<int> ans;
	while(sum > 0 && !v.empty()) {
		if(sum >= v.back().first) {
			sum -= v.back().first;
			ans.push_back(v.back().second);
		}
		v.pop_back();
	}

	if(sum > 0) {
		cout<<-1<<endl;
	}
	else{
		cout<<ans.size()<<endl;
		for (int i=0; i<ans.size(); i++){
			cout<<ans[i]<<' ';
		}cout<<endl;
	}
	return 0;
}
