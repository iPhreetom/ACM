// 总结：
	// 看错题目：以为是抑或
	// 结果是只要判断每个位是否能够操作即可
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int book[2123];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	string a[2123];

	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]=='1'){
				book[j]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		bool ok = 1;
		for(int j=0;j<m;j++){
			if(a[i][j] == '1' && book[j]==1)ok = 0;
		}
		if(ok){
			cout<<"YES"<<endl;
			return 0;
		}
	}

	cout<<"NO"<<endl;
	return 0;
}
