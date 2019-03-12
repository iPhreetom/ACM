#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
int n;
cin >> n;
vector<int> c(212345, 0);
vector<int> t(212345, 0);
for (int i=1; i<=n; i++){
    cin >> c[i];
}
for (int i=1; i<=n; i++){
    cin >> t[i];
}

	if(t[1] != c[1] || c[n] != t[n]){
		cout << "No" << endl;
		return 0;
	}

	int l = 2;
	int r = n-1;
	bool f = 1;
	bool canf = 1;
	bool can = 1;
	while(1) {
		if(l == r) {
			if(c[l] == t[l]){
				cout << "Yes" << endl;
				return 0;
			}
			else{
				if(c[l-1] + c[l+1] - c[l] == t[l]) {
					cout << "Yes" <<endl;
					return 0;
				}
			}
		}

		if(f) {
			if(c[l] == t[l]) {
				l++;
			}
			else{
				if(c[l-1]+c[l+1]-c[l] == t[l]) {
					c[l] = t[l];
					l++;
					canf = 1;
				}
				else {
					canf = 0;
				}
			}
		}
		else{
			if(c[r] == t[r]) {
				r--;
			}
			else {
				if(c[r-1] + c[r+1] - c[r] == t[r]) {
					c[r] = t[r];
					r--;
					can = 1;
				}
				else{
					can = 0;
				}
			}
		}
		f = !f;
		// cout<<"l = "<<l<<endl;
		// cout<<"r = "<<r<<endl;
		if(!canf && !can){
			cout << "No" <<endl;
			return 0;
		}
	}

	return 0;
}
