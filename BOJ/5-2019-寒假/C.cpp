#include<bits/stdc++.h>
// #define int long long
// #define double long double
using namespace std;

int a[212345];
int b[212345];
int t[212345];
int r[212345];
int mx = 0;
int index = 0;
int n,q;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}


	for (int i=1; i<=q; i++){
		cin >> t[i] >> r[i];
		if(r[i] >= mx) {
			mx = r[i];
		}
	}

	vector<pair<int,int>> v;
	int now = 0;

	for(int i=q;i>=1;i--) {
		if(now < r[i]) {
			now = r[i];
			if(!v.empty() && v.back().second == t[i]){
				v.pop_back();
			}
			v.push_back(make_pair(r[i],t[i]));
			if(now == mx) break;
		}
	}
	reverse(v.begin(),v.end());

	if(v.size() <= 1) {
		if(v[0].second == 1) {
			sort(a+1, a+mx+1);
		}
		else{
			sort(a+1, a+mx+1);
			reverse(a+1, a+mx+1);
		}
		for (int i=1; i<=n; i++){
			cout<<a[i]<< ' ';
		}cout<<endl;
		return 0;
	}
	// spj

	int indexl = 1;
	int indexr = 0;
	int index = 0;
	int cnt = v[0].second; // 0 - up

	if(v[0].second == 1) {
		sort(a+1, a+mx+1);
		indexr = v[1].first;
		index = v[1].first;
		indexl = 1;
		for (int i=1; i<=n; i++){
			b[i] = a[i];
		}
	}
	else{
		sort(a+1, a+mx+1);
		reverse(a+1, a+mx+1);
		indexl = mx - v[1].first + 1;
		indexr = mx;
		index = v[1].first;
		for (int i=1; i<=n; i++){
			b[i] = a[i];
		}
		reverse(a+1, a+mx+1);
	}




	v.push_back(make_pair(0,1));

	for (int i=1; i<v.size()-1; i++){
		// for (int i=1; i<=n; i++){
		// 	cout<<b[i]<<' ';
		// }
		// cout<<endl;

		if(cnt == 2) {// 以前是降序
			int nt = v[i+1].first; // 下一个的起点长度
			int dif = v[i].first - nt; // 可以确定的长度
			// 在a中的实际替换位置 右边端点（包含）
			// cout<<"dif = "<<dif<<endl;
			for (int j = 0; j < dif; j++) { // 把坐标开始替换
				b[index] = a[indexr];
				index--;
				// indexl++;
				indexr--;
			}
			cnt = 1;
		}
		else {
			int nt = v[i+1].first; // 下一个的起点长度
			int dif = v[i].first - nt; // 可以确定的长度
			// 在a中的实际替换位置 右边端点（包含）
			// cout<<"dif = "<<dif<<endl;
			for (int j = 0; j < dif; j++) { // 把坐标开始替换
				b[index] = a[indexl];
				index--;
				// indexr--;
				indexl++;
			}
			cnt = 2;
		}
	}

	for (int i=1; i<=n; i++){
		cout<<b[i]<<' ';
	}
	cout<<endl;

	return 0;
}
// 6 3
// 1 2 3 4 5 6
// 2 5
// 1 4
// 2 2
