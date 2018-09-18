// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int cun[3];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	vector<int> a;
	int sum = 0;
	for (int i=0; i<n; i++){
	    int t;cin>>t;
		a.push_back(t);
		if(t == 0)cun[0] = 1;
		if(t > 0)cun[1] = 1;
		if(t < 0)cun[2] = 1;
	}
	if(n == 1){
		sum = a[0];
	}
	else if(cun[0]){
		for(auto i:a){
			sum += abs(i);
		}
	}
	else if(cun[1] && cun[2]){
		for(auto i:a){
			sum += abs(i);
		}
	}
	else if(cun[1]){
		int mn = 1e15;
		for(auto i:a)mn = min(mn,i);
		for(auto i:a){
			sum+=i;
		}
		sum -= mn*2;
	}
	else {
		int mn = 1e15;
		for(auto i:a)mn = min(mn,abs(i));
		for(auto i:a){
			sum+=abs(i);
		}
		sum -= mn*2;
	}
	cout<<sum<<endl;
	return 0;
}
