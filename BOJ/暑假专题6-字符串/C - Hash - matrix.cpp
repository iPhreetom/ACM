
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


vector<string> mt;
vector<int> power;
vector<int> var;
int val[1005][1005];
int aim_num;
int mod = 1304461099;
int base = 1000543273;


int freehash(string &a){
	int seed = 1000543273;
	int num = 0;
	for (int i=0; i<a.size(); i++){
	    num = num*seed + a[i];
		num %= 1304461099;
	}
	return num;
}

void init_pow(){
	int t = 1;
	power.push_back(1);
	for (int i=1; i<=1e6+5; i++){
		t*=base;
		t%=mod;
		power.push_back(t);
	}
}

void init_hash(){

}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init_pow();
	int t;
	cin>>t;
	while(t--){
		mt.clear();
		int ans = 0;
		int x,y,n,m;

		cin>>n>>m;
		if(n == 0 || m == 0)continue;
		string ss;
		for (int i=0; i<n; i++){
			string t;
			cin>>t;
			mt.push_back(t);
			ss += t;
		}

		cin>>x>>y;
		string aim;
		for (int i=0; i<x; i++){
			string t;
			cin>>t;
			aim += t;
		}
		aim_num = freehash(aim);


		int num = 0;
		int index = 0;
		int len = 0;
		// index from 1 ?
		// get big matrix
		for (int i=0; i<ss.size(); i++){
			num = num*base + ss[i];
			num %= mod;
			index = i/m;
			len = i - index*m;
			if(i<n || i%n == 0)val[index][len] = num;
			else val[index][len] = val[index-1][len] + val[index][len-1] - val[index-1][len-1] + num;//var.push_back(var[i-n]+var[i-1]);
		}

		cout<<"aim_num = "<<aim_num<<endl;
		for (int i=0; i<n; i++){
		    for (int j=0; j<m; j++){
		        cout<<val[i][j]<<' ';
		    }cout<<endl;
		}

		for (int i=x-1; i<n; i++){
			for (int j=y-1; j<m; j++){
				cout<<"i = "<<i<<' ';
				cout<<"j = "<<j<<endl;
				if(val[i][j] - val[i-x+1][j] - val[i][j-y+1] + val[i-x+1][j-y+1] == aim_num)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
