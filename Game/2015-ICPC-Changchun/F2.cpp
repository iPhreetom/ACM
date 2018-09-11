#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 1e5 + 5;
vector<int> a;
vector<int> b;

bool checkit(int t){
	return is_sorted(b.begin(),b.end());
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		a.clear();
		int t;

		cin>>n;
		for (int i=1; i<=n; i++){
		    cin>>t;
			a.push_back(t);
		}
		bool ok = 0;
		if(is_sorted(a.begin(),a.end()))ok = 1;
		for (int i=1; i<a.size(); i++){
		    if(a[i]<a[i-1]){
				b = a;
				b.erase(b.begin()+i);
				if(checkit(i)){
					ok = 1;
				}
				b = a;
				b.erase(b.begin()+i-1);
				if(checkit(i-1)){
					ok = 1;
				}
				break;
			}
		}
		reverse(a.begin(),a.end());
		if(is_sorted(a.begin(),a.end()))ok = 1;
		for (int i=1; i<a.size(); i++){
		    if(a[i]<a[i-1]){
				b = a;
				b.erase(b.begin()+i);
				if(checkit(i)){
					ok = 1;
				}
				b = a;
				b.erase(b.begin()+i-1);
				if(checkit(i-1)){
					ok = 1;
				}
				break;
			}
		}
		// for (int i=1; i<a.size(); i++){
		// 	if(a[i]a[i-1]){
		// 		if(checkit2(i)){
		// 			ok = 1;
		// 		}
		// 		else if(checkit2(i-1)){
		// 			ok = 1;
		// 		}
		// 		break;
		// 	}
		// }
		if(ok)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
