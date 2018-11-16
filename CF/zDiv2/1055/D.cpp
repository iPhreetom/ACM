// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string a[3123],b[3123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	for (int i=1; i<=n; i++){
	    cin>>b[i];
	}

	string dif;
	string tag;
	string one = "123";
	string two;

	for (int i=1; i<=n; i++){
		int l=0;
		int r=a[i].size();
		bool same = 0;
		for (int j=0; j<a[i].size(); j++){
			if(a[i][j] != b[i][j]){
				l = j;
				break;
			}
			if(j == a[i].size()-1){
				same = 1;
			}
		}

		if(same)continue;
		for (int j=a[i].size()-1; j>=0; j--){
			if(a[i][j] != b[i][j]){
				r = j;
				break;
			}
		}

		dif = a[i].substr(l,r-l+1);
		tag = b[i].substr(l,r-l+1);
		if(one == "123"){
			one = dif;
			two = tag;
			if(a[i].find(one) != l){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else{
			if(one != dif || two != tag){
				cout<<"NO"<<endl;
				return 0;
			}
			if(a[i].find(one) != l){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	// 先不判断 是否第一次出现，先找不一样的串  在不同的串队中是否相同，然后再试着扩张（n^2）
	// 扩展到最大
	cout<<"YES"<<endl;
	cout<<one<<endl;
	cout<<two<<endl;
	return 0;
}
