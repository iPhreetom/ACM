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

int p[112345];
int prefix[112345];
int l,r;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,n;
	while(1){
		memset(p,0,sizeof(p));
		l=0;
		r=0;

		cin>>c>>n;
		if(c == 0 && n == 0)break;

		for (int i=1; i<=n; i++){
			int t;cin>>t;
			t %= c;
			prefix[i] = (prefix[i-1]+t)%c;

			if(t==0){
				l=i;
				r=i;
				for (int j=i+1; j<=n; j++){
					cin>>t;
				}
				break;
			}
			else if(p[prefix[i]]){
				l = p[prefix[i]]+1;
				r = i;
				for (int j=i+1; j<=n; j++){
					cin>>t;
				}
				break;
			}
			else p[prefix[i]]=i;
		}

		cout<<l;
		for (int i=l+1; i<=r; i++){
		    cout<<' '<<i;
		}cout<<endl;
	}

	return 0;
}
