// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int cnt[1112345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for (int i=1; i<=112345; i++){
		for (int j=i; j<=112345; j++){
			if (i*j > 1112345) break;
			cnt[i*j]++;
		}
	}
	int sum = 0;
	int mx = 0;
	for (int i=1; i<=112345; i++){
		sum += cnt[i];
		mx = max(mx,cnt[i]);
	}
	cout<<"sum = "<<sum<<endl;
	cout<<"mx = "<<mx<<endl;
	return 0;
}
