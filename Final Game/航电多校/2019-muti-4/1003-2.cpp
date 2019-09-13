// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	// ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	vector<int> v;
	for (int i=1; i<=12; i++){
		v.push_back(i);
	}
	while(next_permutation(v.begin(),v.end())){
		// random_shuffle(v.begin(),v.end());
		bool f = 1;
		for (int i=0; i<12; i+=3){
			int num = 0;
			for (int j=i; j<i+3; j++){
				num += v[j];
			}
			if (num != 26) {
				f = 0;
				break;
			}
		}
		if(f){
			for (int i=0; i<v.size(); i++){
			    cout<<v[i]<<' ';
			}cout<<endl;
		}
	}
	cout<<"v.size() = "<<v.size()<<endl;
	return 0;
}
// 15 -> 5
// 24
//
// 1 15 8
// 2 13 9
// 3 10 11
// 4 7 12
// 5
