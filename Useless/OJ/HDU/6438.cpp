// 一句话描述：
// 	贪心 + 优先队列优化
// 知识点：
// 	找到直观贪心策略，使用数据结构优化
// 		每次找到没有被匹配的最小值
// 碎碎念：
// 	一开始看错题意，以为不能赊账，于是瞎想
// 	后来发现题意是 【可以赊账】
//
// 	似乎这种级别的题还是可以写的
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

typedef pair<int,int> pii;
vector<int> a(112345);
const int maxn = 1e14;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		auto que = new(priority_queue<pii,vector<pii>,greater<pii> >);
		int ans = 0;
		int length = 0;


		cin>>n;
		for (int i=1; i<=n; i++){
		    cin>>a[i];
			pii tpnum = make_pair(a[i],maxn);
			while(1){
				// cout<<"length = "<<length<<endl;
				// cout<<"i = "<<i<<endl;
				if(que->empty()){
					que->push(make_pair(tpnum.first,maxn));
				}
				else{
					pii tp = que->top();
					// cout<<"que->top().first = "<<que->top().first<<endl;
					// cout<<endl;
					que->pop();
					if(tp.second == maxn){
						if(tp.first >= tpnum.first){
							que->push(make_pair(tpnum.first,maxn));
							que->push(tp);
						}
						else{
							que->push(make_pair(tpnum.first,tp.first));
							ans += (tpnum.first - tp.first);
							length += 2;
						}
					}
					else{
						if(tp.first >= tpnum.first){
							que->push(make_pair(tpnum.first,maxn));
							que->push(tp);
						}
						else{
							que->push(make_pair(tpnum.first,tp.second));
							ans += (tpnum.first - tp.first);
							tpnum = make_pair(tp.first,maxn);
							continue;
						}
					}
				}
				break;
			}
		}
		cout<<ans<<' '<<length<<endl;
	}
	return 0;
}
