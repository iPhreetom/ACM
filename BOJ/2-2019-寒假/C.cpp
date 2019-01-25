// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>> n;

	if(n < 5){
		if(n == 2)cout<<1<<endl;
		if(n == 3)cout<<3<<endl;
		if(n == 4)cout<<6<<endl;
		return 0;
	}

	vector<int> v;
	int t = 0;
	v.push_back(0);
	for (int i=1; i<=11; i++){
		t *= 10;
		t += 9;
		v.push_back(t);
	}

	int len = 0;
	for (int i=11; i>=1; i--){
		if((2*n-1) >= v[i]) {
			len = i;
			break;
		}
	}

	int sum = 0;
	for (int i=0; i<=9; i++){
		int tp = v[len] + pow(10,len)*i;
		if(n > tp/2) {
			int res = min(n - tp/2, tp/2);
			sum += res;
		}
		else break;
	}
	cout<<sum<<endl;
	return 0;
}

// 9/2 = 4;
// 1 2 3 4 - 5 6 7 8
//
// 19/2 = 9
// 29/2 = 14
// 39/2 = 19
// 89/2 = 44
//
// ---
// 99 / 2 = 49
// 109 / 2 = 54
