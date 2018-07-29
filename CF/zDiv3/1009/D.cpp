#include<bits/stdc++.h>
#define int long long
using namespace std;


int n,m;
set<pair<int,int> > s;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m;

	if(m < n-1){
		cout<<"Impossible"<<endl;
		return 0;
	}

	// for(int i=1;i<=n-1;i++){
	// 	s.insert(make_pair(i,i+1));
	// }

	int cnt=n-1;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(__gcd(i,j) == 1)cnt++;
		}
		if(cnt >= m){
			cout<<"Possible"<<endl;
			break;
		}
	}
	if(cnt < m){
		cout<<"Impossible"<<endl;
		return 0;
	}

	cnt = 0;
	for(int i=1;i<n;i++){
		cout<<i<<' '<<i+1<<'\n';
		cnt++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(cnt==m){
				return 0;
			}
			if(__gcd(i,j) == 1){
				cnt++;
				cout<<i<<' '<<j<<'\n';
			}
			if(cnt==m){
				return 0;
			}
		}
	}
	return 0;
}
