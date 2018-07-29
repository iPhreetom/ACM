// CF 991D bitwocks
// 一句话描述：
// 	贪心（模拟）匹配拼图
// 知识点：
// 	如果要写一个模拟（贪心）
// 		先在草稿上枚举一下会有什么情况，如何应对
// 		包括样例给了的，和样例没给的
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a,b;
ll lu,ld;
ll nu,nd;
ll cur;
ll ans ;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'){
			nu++;
			// lu++;
		}
		if(b[i]=='0'){
			nd++;
			// ld++;
		}

		cur = nu+nd+lu+ld;
		if(cur == 3){
			ans++;
			cur = 0;
			lu=0;
			ld=0;
		}
		else{
			if(cur == 4){
				ans++;
				cur = 0;
				lu=1;
				ld=0;
			}
			else{
				ld = nd;
				lu = nu;
				cur -= lu;
				cur -= ld;
			}
		}
		nd=0;
		nu=0;
	}
	cout<<ans<<endl;
	return 0;
}
