// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[312345];
int b[21234567];
bool p[21234567];
const int maxn = (1.5e7 + 10);

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	int now = a[0];
	for (int i=0; i<n; i++){
	    now = __gcd(a[i],now);
	}
	for (int i=0; i<n; i++){
		a[i] /= now;
		b[a[i]]++;
	}

	bool same = 1;
	for (int i=0; i<n-1; i++){
		if(a[i] != a[i+1])same = 0;
	}
	if(same){
		cout<<-1<<endl;
	}
	else{
		int mx = 0;

		for(int i=2;i<maxn;i++){
			if(p[i] == 0){
				int t = b[i];

				for(int j=i*2; j<maxn; j+=i){
					p[j]=1;
					t += b[j];
				}

				mx = max(mx,t);
			}
		}

		cout<<n-mx<<endl;
	}


	return 0;
}
