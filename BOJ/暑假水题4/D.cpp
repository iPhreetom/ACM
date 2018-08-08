#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
int n;
vector<int> a;
int l , r;
vector<int> ans;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0; i<n; i++){	
	    int t;cin>>t;
		a.push_back(t);
		if(t==1)l++;
		else r++;
	}

	if(l == r){
		cout<<0<<endl;
		return 0;
	}

	int ans = 0;
	for(int i=1;i<=sqrt(n);i++){
		if(n % i == 0){

		}
	}

	return 0;
}
