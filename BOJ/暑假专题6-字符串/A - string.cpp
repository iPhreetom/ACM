
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
#define double long double
using namespace std;

map<string,int> mp;
int n;

signed main(){
	while(scanf("%d",&n)!=EOF){
		mp.clear();
		for (int i=0; i<n; i++){
		    string a;
			char ch[35];
			scanf("%s",ch);
			a = ch;
			mp[a]++;
		}
		int mx=0;
		for(map<string,int>::iterator i=mp.begin();i!=mp.end();i++){
			mx = max(mx,i->second);
		}
		printf("%d\n",mx);
	}
	return 0;
}
