#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int t;
int n,k;
int sum = 0;
int ans[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> t;-
	while(t--) {
		cin >> n >> k;
		sum = 0;
		vector<pair<pair<int,int>,int>> v;
		for (int i=1; i<=n; i++){
			int l,r;
			cin >> l >> r;
			v.push(make_pair(make_pair(l,r),i));
		}
		sort(v.begin(),v.end());
		int index = 0;
		int lt = 0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
		for (int i=0; i<v.size(); i++){
			if(que.empty()) {
				ans[i] = ++index;
				lt = max(lt,v[i].first.first);
				que.push(v[i].first.second);
				index %= k;
			}
			else {
				if(que.size() == k) {

				}
			}
		}
	}
	return 0;
}
