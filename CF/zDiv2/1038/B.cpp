// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	if(n <=2){
		cout<<"No"<<endl;
	}
	else{
		vector<int> l,r;
		for (int i=1; i<=n; i++){
		    if(i%2 == 0){
				l.push_back(i);
			}
			else{
				r.push_back(i);
			}
		}
		cout<<"Yes"<<endl;
		cout<<l.size()<<' ';
		for (int i=0; i<l.size(); i++){
		    cout<<l[i]<<' ';
		}cout<<endl;
		cout<<r.size()<<' ';
		for (int i=0; i<r.size(); i++){
		    cout<<r[i]<<' ';
		}cout<<endl;
	}
	return 0;
}
