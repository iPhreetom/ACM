// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> pre(312345,0);
	vector<int> ans(312345,0);
	int index = 1;
	set<int> has;
	int mx = pow(2,n);
	int len = 1;
	for (int i=1;;){
		ans[i] = index;
		index++;
		pre[i] = pre[i-1]^ans[i];
		int res = pre[i]^x;

		while (has.count(res) != 0 || pre[i] == 0 || has.count(pre[i])!=0) {
			if (index >= mx) break;
			ans[i] = index;
			index++;
			pre[i] = pre[i-1]^ans[i];
			res = pre[i]^x;
		}

		if (index >= mx) break;
		has.insert(pre[i]);
		i++;
		len++;
	}
	cout << len-1 << endl;
	for (int i=1; i<len; i++){
	    cout<<ans[i]<<' ';
	}cout<<endl;
	return 0;
}
