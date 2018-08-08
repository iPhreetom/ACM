#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int n;
int a[112345];
int front[112345];
int back[112345];

inline bool check(int mid){
	// cout<<"---"<<mid<<"----"<<endl;
	front[0] = a[0];
	back[0] = 0;
	int l = a[0];
	int r = mid - a[0];

	for(int i=1;i<n;i++){
		if(i%2 == 1){// front is better
			front[i] = min(a[i],l-front[i-1]);
			back[i] =	a[i] - front[i];
		}
		else{//back is better
			back[i] = min(a[i],r-back[i-1]);
			front[i] = a[i]-back[i];
		}
	}
	if(front[n-1] != 0)return false;
	else return true;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>n){
		memset(front,0,sizeof(front));
		memset(back,0,sizeof(back));
		if(n == 0)return 0;
		int mx = 0,sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
			if(i!=0)mx=max(a[i]+a[i-1],mx);
		}
		mx = max(mx,a[0]+a[n-1]);
		if(n == 1){
			cout<<a[0]<<endl;
			continue;
		}
		if(n%2 == 0){
			cout<<mx<<endl;
		}
		else{
			int l = mx;
			int r = sum+1;
			while(l+1 < r){
				int mid = l+(r-l)/2;
				if(check(mid))r = mid;
				else l = mid;
			}
			// cout<<l<<' '<<r<<endl;
			if(check(min(l,r))){
				cout<<min(l,r)<<endl;
			}else{
				cout<<max(l,r)<<endl;
			}
		}
	}
	return 0;
}
