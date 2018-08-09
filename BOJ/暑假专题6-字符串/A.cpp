
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

// get prime
// get hash


int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

int freehash(string &a){
	int seed = 1000543273;
	int num = 0;
	for (int i=0; i<a.size(); i++){
	    num = num*seed + a[i];
		num %= 1304461099;
	}
	return num;
}

int free2hash(string &b){
	int seed = 131313131;
	int num = 0;
	for (int i=0; i<b.size(); i++){
	    num = num*seed + b[i];
		num %= (int)(1e9+7);
	}
	return num;
}

int free3hash(string &b){
	int seed = 10369;
	int num = 0;
	for (int i=0; i<b.size(); i++){
	    num = num*seed + b[i];
		num %= 99581;
	}
	return num;
}

int n;

bool isprime(int a){
	for (int i=2; i<=sqrt(a); i++){
	    if(a%i == 0)return 0;
	}
	return 1;
}

void getprime(){
	int ans = 0;
	for (int i=1e9+3e8; i<2e9; i++){
		if(isprime(i)){ans++;cout<<i<<endl;}
		if(ans == 1313131){
			ans = i;
			break;
		}
	}
	cout<<ans<<endl;
}

map<pair<pair<int,int>,int>,int> mp;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	while(cin>>n){
		mp.clear();
		for (int i=0; i<n; i++){
		    string a;
			char cs[35];
			scanf("%s",cs);
			a = cs;
			int j;
			for(j=0;j<a.size();j++){
				if(a[j] != '0')break;
			}
			a = a.substr(j);
			mp[make_pair(make_pair( free2hash(a),free3hash(a) ),freehash(a))]++;
			// cout<<"a = "<<a<<' '<<freehash(a)<<' '<<free2hash(a)<<' '<<free3hash(a)<<endl;
		}
		int mx = 0;
		for(map<pair<pair<int,int>,int>,int>::iterator i=mp.begin();i!=mp.end();i++){
			mx = max(mx,i->second);
		}
		printf("%d\n",mx);
	}

	return 0;
}
