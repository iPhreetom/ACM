
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
#define int long long
#define double long double
using namespace std;

const int base = 2333;
const int mod = 1304461099;
int f[1005];
int big_hash [1005][1005];
int small_hash [105];
int x,y,n,m;
int ans;
vector<int> power;

void init_pow(){
	int t = 1;
	power.push_back(1);
	for (int i=1; i<=1e6+5; i++){
		t*=base;
		t%=mod;
		power.push_back(t);
	}
}

void getFail(){
	f[0] = 0;
	f[1] = 0;
	for (int i=1; i<y; i++){
	    int j = f[i];
		while(j && small_hash[i]!=small_hash[j])j = f[j];
		f[i+1] = small_hash[i] == small_hash[j]? j+1 : 0;
	}
}

void findnum(int index){
	int a[1005];
	for (int i=0; i<m; i++){
		if(index == 0)a[i] = big_hash[index+x-1][i];
		else a[i] = (big_hash[index+x-1][i] - (big_hash[index-1][i] * power[x])%mod + mod) % mod;
	}

	int j = 0;
	for (int i=0; i<m; i++){
		while(j && small_hash[j] != a[i])j = f[j];
		if(small_hash[j] == a[i])j++;
		if(j == y){
			ans++;
			j = f[j];
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init_pow();
	int t;cin>>t;
	while(t--){
		memset(small_hash,0,sizeof(small_hash));
		memset(big_hash,0,sizeof(big_hash));
		memset(f,0,sizeof(f));
		ans = 0;
		cin>>n>>m;
		for (int i=0; i<n; i++){
			string s;
			cin>>s;
			for (int j=0; j<s.size(); j++){
				if(i == 0)big_hash[i][j] = s[j];
				else big_hash[i][j] = ((big_hash[i-1][j]*base)%mod + s[j])%mod;
			}
		}



		cin>>x>>y;
		for (int i=0; i<x; i++){
			string s;
			cin>>s;
			for (int j=0; j<s.size(); j++){
				small_hash[j] = ((small_hash[j]*base)%mod + s[j])%mod;
			}
		}

		getFail();
		for (int i=0; i<=n-x; i++){
			findnum(i);
			// cout<<"--"<<endl;
		}
		cout<<ans<<endl;


	}
	return 0;
}
