#include<bits/stdc++.h>
#define int long long
// #define double long double
using namespace std;

int t;
int n,m,k,p,q,r,mod;
int a[10000009];



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		// deque<pair<int,int>> que;
        list<pair<int,int>> que;
        cin>>n>>m>>k>>p>>q>>r>>mod;
		for(int i=1;i<=k;i++){
			cin>>a[i];
		}
		for(int i=k+1;i<=n;i++){
			a[i] = (a[i-1]*p + q*i + r)%mod;
		}
		int mx = 0;
		int A=0;
		int B=0;
		mx = -1;

		for(int i=n-m+1;i<=n;i++){
			if(a[i] > mx){
				mx = a[i];
				que.push_back({a[i],i});
			}
		}
        //cout<<mx<<que.size()<<que.size()<<endl;
		A += (mx^(n-m+1));
		B += (que.size()^(n-m+1));


		for(int i=n-m;i>=1;i--){
			if(i+m == que.back().second){
				que.pop_back();
				mx = que.back().first;
			}

			// cout<<"--11"<<endl;

			if(a[i] < que.front().first){
				que.push_front({a[i],i});
			}
			else if(a[i] == que.front().first){
				que.pop_front();
				que.push_front({a[i],i});
			}else{
				while(!que.empty() && que.front().first<a[i]){
					que.pop_front();
				}
				que.push_front({a[i],i});
			}
			A += (mx^i);
			B += (que.size()^i);
		}
        cout<<A<<' '<<B<<'\n';
	}
	return 0;
}
// 1
// 10 6 10 5 5 5 5
// 0 0 0 0 0 0 0 0 0 0
