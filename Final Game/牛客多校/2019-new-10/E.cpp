// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

pair<int,int> rotleft(int len, int x,int y) {
	return {y,x};
}
pair<int,int> rotright(int len, int x, int y) {
	return {len-y+1,len-x+1};
}

int getit(int len , int x,int y) {
	if (len == 2) {
		int ret = 0;
		if (x == 1 && y == 1) ret = 1;
		else if(x == 2 && y == 1) ret = 2;
		else if (x == 2 && y == 2) ret = 3;
		else ret = 4;
		return ret;
	}

	if (x <= len/2 && y <=len/2) {
		// left top
		auto tp = rotleft(len/2,x,y);
		x = tp.first;
		y = tp.second;
		return getit(len/2,x,y);
	}
	else if(x <= len/2 && y>len/2) {
		// right top
		auto tp = rotright(len/2,x,y-len/2);
		x = tp.first;
		y = tp.second;
		return getit(len/2,x,y)+len*len-len/2*len/2;
	}
	else {
		// bottom
		if (y <= len/2) {
			return len/2*len/2 + getit(len/2,x-len/2, y);
		}
		else {
			return len/2*len + getit(len/2, x-len/2, y-len/2);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int len = (1LL<<m);
	vector<int> x(n),y(n);
	vector<pair<int,pair<int,int>>> ans;

	for (int i=0; i<n; i++){
		cin >> x[i] >> y[i];
		ans.push_back({getit(len,x[i],y[i]),{x[i],y[i]}});
	}

	sort(ans.begin(),ans.end());
	for (int i=0; i<ans.size(); i++){
		// cout << ans[i].first << endl;
		cout << ans[i].second.first << ' ' << ans[i].second.second << endl;
	}
	return 0;
}
