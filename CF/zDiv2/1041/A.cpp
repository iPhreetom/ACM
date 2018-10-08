#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,m;
	cin>>n>>m;

	int sum = 0;
	for (int i=0; i<n; i++){
	    int t;
		cin>>t;
		sum += t;
	}

	sum = abs(sum);
	int ans = sum / m;
	if(sum % m != 0)ans++;

	cout<<ans<<endl;
	return 0;
}
