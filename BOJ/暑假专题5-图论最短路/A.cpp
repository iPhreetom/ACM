// wait for me


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
using namespace std;


struct node{
	int c;
	int lv;
	vector<pair<int,int>> rp;
};
node arr[105];
bool vis[105];

int m,n;

int dfs(int index,int mxlv,int mnlv){
	node &no = arr[index];
	int mn = no.c;

	for (int i=0; i<no.rp.size(); i++){
		node &nno = arr[no.rp[i].first];
		if(nno.lv+m >= mxlv && mnlv+m >= nno.lv){
			if(vis[no.rp[i].first] == 0){
				vis[no.rp[i].first]=1;
				mn = min(dfs(no.rp[i].first , max(mxlv,nno.lv) ,min(mnlv,nno.lv))+no.rp[i].second,mn);
				// if(index==1)cout<<"mn = "<<mn<<endl;
				vis[no.rp[i].first]=0;
			}
		}
	}

	return mn;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>m>>n;
	for (int i=1; i<=n; i++){
		int c,lv,k;
		cin>>c>>lv>>k;
		node &no = arr[i];
		no.c = c;
		no.lv = lv;
		for (int j=0; j<k; j++){
		    int num,c2;
			cin>>num>>c2;
			no.rp.push_back(make_pair(num,c2));
		}
	}
	// cout<<"FINISH"<<endl;
	vis[1]=1;
	cout<<dfs(1,arr[1].lv,arr[1].lv)<<endl;
	return 0;
}
