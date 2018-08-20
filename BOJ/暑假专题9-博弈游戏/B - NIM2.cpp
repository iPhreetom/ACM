// UVA 11892
// 	一句话描述：
// 		不对称博弈游戏
// 	知识点：
// 		先取得一方必胜
// 		先取的一方获胜情况多，失败情况少
// 		先考虑少的那种情况
// 	碎碎念：
// 		这种题目不是经常有么
// 		先手必胜
// 		没有最优策略（优美的平衡）
// 		这道题的严格规则，导致了先手的优势巨大
// 		所以就可以考虑一下，先手会输的简单情况
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

set<int> ans;
void pre(int i){
	ans.insert(i);
	if(i < 2e18 && i > 0){
		pre(i*2 + 1);
	}
}

void solve(){
	int n,num=0;
	cin>>n;
	vector<int> a(n);
	map<int,int> mp;
	for (int i=0; i<n; i++){
	    cin>>a[i];
		if(a[i] != 1){
			num ^= a[i];
			mp[a[i]]++;
		}
	}
	bool win = 0;
	for(auto i:mp){
		if(i.second % 2 == 0){
			win = win;
		}
		else{
			if(ans.count(i.first) == 0){
				win = !win;
			}
			else{
				win = win;
			}
		}
	}

	if(win == 1){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	pre(1);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
