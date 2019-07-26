// POJ 1321 功能分开的大模拟实现，只要思路清晰，就可以完成

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

string mp[10];
vector<pair<int,int> > v;
int dp[10][10];
int n,k;
bool lx[10];
bool ly[10];

bool check(pair<int,int>& p){
	int x = p.first;
	int y = p.second;
	if(lx[x] || ly[y])return 0;
	return 1;
}

int findnx(int index,int res){
	int sum = 0;
	if(res == 0)return 1;
	if(index == v.size())return 0;

	for(index;index<v.size();index++){
		// cout<<"index = "<<index<<endl;
		if(check(v[index])){
			// cout<<"index = "<<index<<endl;
			int x = v[index].first;
			int y = v[index].second;
			lx[x] = 1;
			ly[y] = 1;
			sum += findnx(index+1,res-1);
			lx[x] = 0;
			ly[y] = 0;
			// break;
		}
	}

	return sum;
}



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(1){
		memset(lx,0,sizeof(lx));
		memset(ly,0,sizeof(ly));
		memset(dp,0,sizeof(dp));
		v.clear();

		cin>>n>>k;
		if(n == -1 && k == -1)break;

		int sum = 0;
		for (int i=0; i<n; i++){
			cin>>mp[i];
			for (int j=0; j<mp[i].size(); j++){
				if(mp[i][j] == '#'){
					v.push_back(make_pair(i,j));
				}
			}
		}
		// cout<<"v.size() = "<<v.size()<<endl;
		sum = findnx(0,k);
		cout<<sum<<endl;
	}

	return 0;
}
