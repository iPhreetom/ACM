#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int n;
vector<int> c(212345, 0);
vector<int> t(212345, 0);

bool can = 1;
void solve(int l,int r) {
	if(!can) return;
	if(l == r) {
		if(c[l] == t[l])return ;
		if(c[l+1] + c[l-1] -c[l] == t[l]){
			c[l] = t[l];

		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++){
	    cin >> c[i];
	}
	for (int i=1; i<=n; i++){
	    cin >> t[i];
	}
	return 0;
}
