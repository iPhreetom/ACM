// CF 982B 最大值与最小值的匹配问题
 	// 利用优先队列可以快速匹配
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

priority_queue<pll> q;
vector<pll> a;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll t;
		cin>>t;
		a.push_back(make_pair(t,i));
	}

	sort(a.begin(),a.end());

	string s;
	cin>>s;

	int j = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			q.push(a[j]);
			cout<<a[j].second<<' ';
			j++;
		}
		else{
			cout<<q.top().second<<' ';
			q.pop();
		}
	}
	return 0;
}
