#include<bits/stdc++.h>
using namespace std;


long long n,k;
vector<long long> a;
long long t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	long long val,index=0;
	long long count=0;
	long long ans=0;
	while(count<k){
		val = a[index];
		for(;index<n;index++){
			if(val == a[index])count++;
			else break;
		}
		if(count == k){
			ans = a[index-1];
		}
		if(count > k)ans = -1;
	}
	if(k == 0){
		if(a[0] == 1)ans = -1;
		else ans = 1;
	}
	cout<<ans<<endl;

	return 0;
}
