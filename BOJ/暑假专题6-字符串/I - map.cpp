// fyt

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
#define endl '\n'
#define int long long
#define double long double
using namespace std;

string a;
map<string,int> mp;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	double sum = 0;
	while(getline(cin,a)){
		mp[a]++;
		sum+=1;
	}
	for (map<string,int>::iterator i = mp.begin() ; i != mp.end();i++){
		cout<<fixed<<setprecision(4)<<i->first<<' '<<i->second/sum*100<<endl;
	}
	return 0;
}
