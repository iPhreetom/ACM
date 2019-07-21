// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int mas[1123];
int sam;
int n,k;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	sam = n/2;
	sam += n%2;
	int num = 0;
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		mas[t]++;
	}
	for (int i=1; i<=k; i++){
		num += (mas[i]/2)*2;
		sam -= mas[i]/2;
		mas[i]%=2;
	}
	int cnt = 0;
	while(sam > 0) {
		if (mas[cnt] == 1) {
			sam--;
			num++;
		}
		cnt++;
	}
	cout << num << endl;
	return 0;
}
