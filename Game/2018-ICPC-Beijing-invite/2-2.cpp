#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		vector<string> a;
		string f = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i=0; i<n; i++){
			string t;
			cin>>t;
			t += t;
			if(t.size() < f.size())f = t;
			a.push_back(t);
		}

		if(n == 1){
			cout<<f.substr(0,f.size()/2)<<endl;
			continue;
		}

		vector<string> ans[11];
		for (int j=0; j<n; j++){
			for (int i=0; i<a[j].size()/2; i++){
				ans[j].push_back(a[j].substr(i,a[j].size()/2));
			}
		}
		// cout<<"1 = "<<1<<endl;

		// 处理所有的字符串的所有子串
		set<string> s[11];
		vector<string> my;
		for (int i=0; i<n; i++){
			while(ans[i][0].size() != 0){
				for (int j=0; j<ans[i].size(); j++){
					s[i].insert(ans[i][j]);
					if(i == 0){
						my.push_back(ans[i][j]);
					}
				}
				for (int j=0; j<ans[i].size(); j++){
					ans[i][j].pop_back();
				}
			}
		}
		// cout<<"2 = "<<2<<endl;
		// return 0;

		// 定义比较
		auto cmp = [](string &a,string &b){
			if(a.size() != b.size()){
				return a.size() < b.size();
			}
			else{
				return a<b;
			}
		};
		sort(my.begin(),my.end(),cmp);
		for (int i=0; i<my.size(); i++){
		    cout<<my[i]<<' ';
		}cout<<endl;

		// 暴力寻找
		bool flag = 1;
		for (int i=0; flag && i<=my.size(); i++){
			if(i == my.size()){
				cout<<0<<endl;
				break;
			}
			else{
				int sum = 0;
				for (int i=0; i<n; i++){
					if(s[i].count(my[i]) != 0){
						sum++;
					}
				}
				if(sum == n){
					cout<<my[i]<<endl;
					flag = 0;
					break;
				}
			}
			// cout<<"my = "<<my<<endl;
		}
	}
	return 0;
}
