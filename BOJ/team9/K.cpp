#include<bits/stdc++.h>
using namespace std;

set<long long> a;
long long n;
long long b;
long long ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>b;
		if(a.count(b) == 0){
			a.insert(b);
		}
		else{
			ans++;
		}
	}
	cout<<ans<<endl;

	return 0;
}
