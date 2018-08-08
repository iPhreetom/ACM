#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

typedef pair<int,pair<int,int> > pii;
priority_queue<pii,vector<pii>,greater<pii> > que1;
priority_queue<pii,vector<pii>,greater<pii> > que2;
bool used[112345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int t = 0;
	cin>>t;
	while(t--){
		int ans = 0,n;
		string s;

		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s;
			int l=0,r=0;
			for(auto j:s){
				if(j == '('){
					l++;
				}else if(l > 0){
					l--;
				}else {
					r++;
				}
			}
			que1.push(make_pair(l,make_pair(r,i)));
			que1.push(make_pair(r,make_pair(l,i)));
		}
		string sans;

	}
	return 0;
}
