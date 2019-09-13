// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("in.txt","w",stdout);
	cout << 3 << endl;
	for (int i=0; i<3; i++){
		vector<int> v;
		cout << 50000 << endl;
	    for (int j=1; j<=5e4; j++){
			v.push_back(j);
	    }
		random_shuffle(v.begin(),v.end());
		for (int j=0; j<5e4; j++){
			cout << v[j] << (j==(5e4-1)?'\n':' ');
		}
		random_shuffle(v.begin(),v.end());
		for (int j=0; j<5e4; j++){
			cout << v[j] << (j==(5e4-1)?'\n':' ');
		}
	}
	return 0;
}
