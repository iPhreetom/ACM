读题小法坏
我要练习阅读英语题面的能力（尤其是公式
	首先，放空自己去理解，试着问自己：这个是什么意思呢？
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

string mtx[5212];
string s;
bool mp[5212][5212];
int n;

int code[16][4] = {
	{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},
	{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},
	{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},
	{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}
};

bool check(int div) {
	for (int i=div; i<=n; i+=div){
		for (int j=div; j<=n; j+=div){
			// check directly
			for (int ii = i-div+1; ii <= i; ii++) {
				for (int jj = j-div+1; jj <= j; jj++) {
					if(mp[i][j] != mp[ii][jj])return 0;
				}
			}
		}
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> s;
		int index = 0;
		for (int j=0; j<s.size(); j++){
			for(int k=0;k<4;k++){
				mp[i][++index] = code[s[j] <= '9'?s[j]-'0':s[j]-'A'+10][k];
			}
		}
	}
	// for (int i=1; i<=n; i++){
	// 	for (int j=1; j<=n; j++){
	// 	    cout<<mp[i][j];
	// 	}cout<<endl;
	// }
	int ans = 1;
	vector<int> root;
	for (int i=2; i<=n; i++){
		if(n%i == 0) {
			root.push_back(i);
		}
	}

	for (int i=0; i<root.size(); i++){
	    if(check(root[i])) {
			ans = root[i];
		}
	}

	cout << ans << endl;
	return 0;
}
