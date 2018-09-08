#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> arr;
map<int,int> m;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(m.count(t) == 0){
			m[t] = 1;
			cout<<1<<' ';
		}
		else{
			int index = 1;
			while(1){
				t--;
				index++;
				if(m.count(t) == 0){
					m[t] = 1;
					cout<<index<<' ';
					break;
				}
			}
		}
	}
	cout<<endl;
	return 0;
}
