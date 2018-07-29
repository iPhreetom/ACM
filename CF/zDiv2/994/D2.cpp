// CF 994D Open Communicate
// 	一句话描述：
// 		按照题意模拟（思维）
// 	总结：
// 		1、心态：
// 			一切的乐趣，都可以在做完所有题目后慢慢诉说
// 			所以，遇到看上去不怎么会做的题目
// 			相信自己，在肝出来后，会在代码的尾端写上（easy）的注释
// 		2、修正：
// 			当一开始的解决方案不够优秀时，换个思路实现一遍
// 			可以更加有效率（重构的艺术）

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ansa[65];
bool ansb[65];
vector<pair<ll,ll> > a,b;
ll n,m;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;

	ll x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		a.push_back(make_pair(x,y));
	}
	for(int i=0;i<m;i++){
		cin>>x>>y;
		b.push_back(make_pair(x,y));
	}

	// 找a是否可以判断出b和他拥有共用同一个key
	for(int i=0;i<n;i++){
		set<ll> se;
		set<ll> key;
		se.insert(a[i].first);
		se.insert(a[i].second);

		for(int j=0;j<m;j++){
			if(se.find(b[j].first) != se.end()){
				if(se.find(b[j].second) == se.end()){
					key.insert(b[j].first);
				}
			}
			if(se.find(b[j].second) != se.end()){
				if(se.find(b[j].first) == se.end()){
					key.insert(b[j].second);
				}
			}
		}

		if(key.size() == 0)continue;

		if(key.size() == 2){
			cout<<-1<<endl;
			return 0;
		}
		else{
			ansa[*key.begin()]=1;
		}
	}

	for(int i=0;i<m;i++){
		set<ll> se;
		set<ll> key;
		se.insert(b[i].first);
		se.insert(b[i].second);

		for(int j=0;j<n;j++){
			if(se.find(a[j].first) != se.end()){
				if(se.find(a[j].second) == se.end()){
					key.insert(a[j].first);
				}
			}
			if(se.find(a[j].second) != se.end()){
				if(se.find(a[j].first) == se.end()){
					key.insert(a[j].second);
				}
			}
		}

		if(key.size() == 0)continue;

		if(key.size() == 2){
			cout<<-1<<endl;
			return 0;
		}
		else{
			ansb[*key.begin()]=1;
		}
	}

	int sum = 0;
	ll ans = 0;
	for(int i=0;i<65;i++){
		if(ansa[i] && ansb[i]){
			sum++;
			ans = i;
		}
		else if(ansa[i] || ansb[i]){
			cout<<-1<<endl;
			return 0;
		}
	}

	if(sum == 0){
		cout<<-1<<endl;
	}
	if(sum == 1){
		// cout<<1<<endl;
		cout<<ans<<endl;
	}
	if(sum > 1){
		cout<<0<<endl;
	}
	return 0;
}
// easy
