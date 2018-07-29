
#include<bits/stdc++.h>
using namespace std;


// int a[5000];
// int b[5000];
vector<pair<int,int> > a(30043);
long long arr[3003];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	long long n,v;
	cin>>n>>v;

	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}

	sort(a.begin(),a.begin()+n);
	long long llas=0;
	long long last=0;
	long long now = 0;

	long long ans = 0;



	for(auto i:a){
		arr[i.first] += i.second;
	}
	int vp = v;
	for(int i=1;i<=3001;i++){
		v = vp;
		ans += min(arr[i-1],(long long)v);
		v -= min(arr[i-1],(long long)v);
		if(v > arr[i]){
			ans += arr[i];
			arr[i]=0;
		}
		else{
			ans += v;
			arr[i]-=v;
		}
	}
	// cout<<v<<endl;
	cout<<ans<<endl;

	return 0;
}
