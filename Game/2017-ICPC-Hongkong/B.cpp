#include<bits/stdc++.h>
#define int long long
//#define double long double
#define endl '\n'
using namespace std;

vector<int> a;
int n,m;

bool check(int t){
	int sum = 1;
	int tp = a[0];
	for (int i=1; sum < m && i<a.size(); i++){
		if(a[i] >= tp+t){
			tp = a[i];
			sum++;
		}
	}
	if(sum >= m){
		return 1;
	}
	else{
		return 0;
	}
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	while(cin>>n>>m){
		if(n == 0 && m == 0)break;
		a.clear();
		a.resize(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a.begin(),a.end());
		int l = 1;
		int r = a.back()+1;

		while(l+1<r){
			int mid = l+(r-l)/2;
			if(check(mid))l = mid;
			else r = mid;
		}

		if(check(r)){
			cout<<r<<endl;
		}
		else{
			cout<<l<<endl;
		}
	}
    return 0;
}
