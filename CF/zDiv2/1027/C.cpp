#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int lis[11234];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		// vector<int> a;
		int t;
		map<int,int> mp;
		memset(lis,0,sizeof(lis));

		cin>>n;
		for (int i=0; i<n; i++){
			cin>>t;
			// a.push_back(t);
			// lis[t]++;
			mp[t]++;
		}

		// sort(a.begin(),a.end());
		bool findit = 0;
		int last = 0;
		int right = 0;
		int ans1,ans2;
		double ans = 1e10;

		for (auto q = mp.begin();q != mp.end() && !findit;q++){
			int i = q->first;
			int num = q->second;

		    if(num>1){
				if(num >= 4){
					findit = 1;
					cout<<i<<' '<<i<<' '<<i<<' '<<i<<endl;
				}
				else{
					if(last == 0){
						last = i;
					}
					else{
						double t1,t2;
						t1 = last;
						t2 = i;
						if(ans > (8+4*(t1/t2 + t2/t1))){
							ans = (8+4*(t1/t2 + t2/t1));
							ans1 = last;
							ans2 = i;
						}
						last = i;
					}
				}
			}
		}

		if(!findit){
			cout<<ans1<<' '<<ans1<<' '<<ans2<<' '<<ans2<<endl;
		}
	}
	return 0;
}
