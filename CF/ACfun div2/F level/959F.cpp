// CF 959F XOR task
// 	一句话描述：
// 		基于x^x=0 和 抑或交换律 的题目
// 	知识点：
// 		抑或性质：
			// 当 只前的数列出现过x时，再一次添加x，那么组成任意可以组成的数的方法*2（因为同时取，也可以同时不取）
			// 	如果我们需要 组成的数就是x，那么就是，取一个x不取另一个x。方案数仍旧*2
// 			所以只要用列表存下，现在的元素能够组成的所有数。
// 				当新加入元素时，如果没有出现，那么就和已知元素抑或。
// 			通过 交换律 的性质知道，这个最多 在元素列表中添加 1e5个元素，这个复杂度可以忽略
// 		查询答案性质：
// 			离线处理：（通过离线变成，按某种顺序的在线处理）
// 			在线处理：
// 	总结：
// 		这道题，如果细细分析，其实可以做出来。


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


ll a[212345];
ll ans[212345];
ll book[1<<20 +5];


vector<pair<pair<ll,ll>,ll> > q;
ll index=0;
ll n,nq;
ll mod = 1e9+7;

vector<ll> lis;
ll zero=0;


long long powMod(long long a, long long b)
{
	long long res = 1;
	long long base = a % mod;
	while (b)
	{
		if (b & 1) res = res * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll same=1;
	cin>>n>>nq;
	book[0]=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}

	for(ll i=1;i<=nq;i++){
		ll l,x;
		cin>>l>>x;
		q.push_back(make_pair(make_pair(l,x),i));
	}
	sort(q.begin(),q.end());

	// index == 0
	for(ll i=1;i<=n;i++){
		ll len = lis.size();

		if(book[a[i]] == 0){
			for(ll j=0;j<len;j++){
				lis.push_back(a[i]^lis[j]);
				book[a[i]^lis[j]]=1;
			}
			lis.push_back(a[i]);
			book[a[i]]=1;
		}
		else{
			// book[a[i]]++;
			same = same*2%mod;
		}

		while(index<nq && q[index].first.first == i){
			if(book[q[index].first.second] == 0){
				// cout<<"??"<<endl;
				ans[q[index].second] = 0;
			}
			else{
				ans[q[index].second] = same;//powMod(2,book[q[index].first.second]+zero-1);
				// cout<<"----"<<endl;
				// std::cout << q[index].second << "\n";
			}
			index++;
		}
	}
	for(ll i=1;i<=nq;i++){
		cout<<ans[i]<<endl;
	}



	return 0;
}
