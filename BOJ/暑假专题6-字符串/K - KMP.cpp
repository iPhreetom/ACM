
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


vector<int> f;
void getFail(string &p){
	f[0] = 0;
	f[1] = 0;
	for (int i=1; i<p.size(); i++){
	    int j = f[i];
		while(j && p[i]!=p[j])j = f[j];
		f[i+1] = p[i] == p[j]? j+1 : 0;
	}
}

void findnum(string &a,string &b){
	f.resize(b.size()+1);
	getFail(b);
	int j = 0;
	int ans = 0;
	for (int i=0; i<a.size(); i++){
		while(j && b[j] != a[i])j = f[j];
		if(b[j] == a[i])j++;
		if(j == b.size())ans++;//find one
	}
	cout<<ans<<endl;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		findnum(b,a);
	}
	return 0;
}
