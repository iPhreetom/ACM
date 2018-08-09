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

int n;
bool a[51234];
struct edge{
	int l;
	int r;
	int c;
	edge(int l,int r,int c){
		this->l=l;
		this->r=r;
		this->c=c;
	}
};

vector<edge> arr;

// vector<pair<int,int> > arr;
int s[51234];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0; i<n; i++){
		int l,r,c;
		cin>>l>>r>>c;
		arr.push_back(edge(l,r,c));
	}

	return 0;
}
