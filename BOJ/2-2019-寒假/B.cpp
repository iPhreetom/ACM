// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];
int num[212345];
int n, m;

void getit() {
	a[0] = -1e9;
	for (int i=n; i>=2; i--){
		if(a[i] == a[i-1]) {
			num[i-1] = num[i]+1;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	getit();
	while(m--) {
		int l, r, x;
		cin >> l >> r >> x;
		if(a[l] == x) {
			if(num[l] >= (r-l)) {
				cout<<-1<<endl;
			}
			else{
				cout<<l + num[l] + 1<<endl;
			}
		}
		else{
			cout<<l<<endl;
		}
	}
	return 0;
}
