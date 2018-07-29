
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
string a[102];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>m>>n;
	char tp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>tp;
			a[j].push_back(tp);
			a[j].push_back(tp);
		}
	}
	for(int i=0;i<m;i++){
		// reverse(a[i].begin(),a[i].end());
		cout<<a[i]<<endl<<a[i]<<endl;
	}

	return 0;
}
