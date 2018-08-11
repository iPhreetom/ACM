
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

vector<int> a1;
vector<int> a2;

vector<int> f;
void getFail(vector<int> &p){
	f[0] = 0;
	f[1] = 0;
	for (int i=1; i<p.size(); i++){
	    int j = f[i];
		while(j && p[i]!=p[j])j = f[j];
		f[i+1] = p[i] == p[j]? j+1 : 0;
	}
}

void findnum(vector<int> &a,vector<int> &b){
	f.resize(b.size()+1);
	getFail(b);
	int j = 0;
	int ans = 0;
	for (int i=0; i<a.size(); i++){
		while(j && b[j] != a[i])j = f[j];
		if(b[j] == a[i])j++;
		if(j == b.size()){
			ans = i+1 - b.size()+1;
			break;
		};//find one
	}
	if(ans == 0)ans = -1;
	cout<<ans<<endl;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int a,b;
		a1.clear();
		a2.clear();

		cin>>a>>b;
		for (int i=0; i<a; i++){
			int c;
			cin>>c;
			a1.push_back(c);
		}

		for (int i=0; i<b; i++){
		    int c;
			cin>>c;
			a2.push_back(c);
		}

		findnum(a1,a2);
	}
	return 0;
}
