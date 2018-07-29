#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a[10];
vector<ll> ans;
bool book[10];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		book[t] = 1;
	}

	for(int i=0;i<n;i++){
		if(book[a[i]]==1){
			ans.push_back(a[i]);
		}
	}

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';

	}
	return 0;
}
