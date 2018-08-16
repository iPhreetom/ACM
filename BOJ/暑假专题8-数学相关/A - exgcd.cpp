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

int exgcd(int a,int b,int &x,int &y){
    int result = a;
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        result = exgcd(b,a%b,y,x);
        y -= (a/b)*x;
    }
    return result;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int x,y,n,m,l;
    int xx,yy;
	cin>>x>>y>>m>>n>>l;

    if(m>n){
        swap(m,n);
        swap(x,y);
    }
    int divisor = exgcd((n-m),l,xx,yy);

	if((x-y) % divisor != 0){
		cout<<"Impossible"<<endl;
	}
	else{
        int ans = xx/divisor*(x-y);
        while(ans < 0)ans+=l;
        cout<<ans<<endl;
	}
	return 0;
}
