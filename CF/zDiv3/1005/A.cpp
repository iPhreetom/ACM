#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	int f=0;
	vector<int> ans;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t>f){
			f++;
		}
		else{
			ans.push_back(f);
			f=1;
		}
	}
	ans.push_back(f);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	return 0;
}
