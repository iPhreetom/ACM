// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	set<int> fin;
	set<int> ls;
	for (int i=1; i<=n; i++){
		set<int> tp;
		set<int> res;
		int t;
		cin>>t;
		for (int j=0; j<t; j++){
			int num;
			cin>>num;
			tp.insert(num);
		}
		if(ls.empty()){
			ls = tp;
		}
		else{
			for(auto i:tp){
				if(ls.count(i) != 0){
					res.insert(i);
				}
			}
			ls = res;
		}
	}
	for(auto i:ls){
		cout<<i<<' ';
	}
	cout<<endl;
	return 0;
}
