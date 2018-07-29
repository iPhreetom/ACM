#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,d;
int sum ;
int index = 2;

void dfs(int num,int dp,int eg){
	if(dp >= d)return;
	if(sum == 0)return;

	for(int i=num;i<num+(k-eg);i++){
		if(sum == 0)break;
		cout<<num<<' '<<index<<'\n';
		sum--;
		// cout<<sum<<endl;
		dfs(index++,dp+1,1);
	}
}

void bfs(int num,int dp,int eg){

}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>d>>k;
	sum = n;
	sum--;

	if(n == 1){
		cout<<"YES"<<endl;
		return 0;
	}
	if(d > n){
		// n != 1
		cout<<"NO"<<endl;
		return 0;
	}
	if(k == 1){
		// n != 1
		cout<<"NO"<<endl;
		return 0;
	}

	ll maxn = 1;
	ll last = 1;
	for(int i=2;i<=d;i++){
		if(i == 2){
			maxn += last * k;
			last = last * k;
			continue;
		}
		maxn += last*(k-1);
		last = last*(k-1);
		if(maxn > 4e5+5)break;
		// cout<<maxn<<endl;
	}

	if(maxn < n){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		dfs(1,1,0);
	}
	return 0;
}

/*
if(k == 1){
	if(n == 1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}

ll maxn=1;
ll last = 1;
for(int i=2;i<=d;i++){
	if(i == 2){
		maxn += last * k;
		last = last * k;
		continue;
	}
	maxn += last*(k-1);
	last = last*(k-1);
	if(maxn > 4e5+5)break;
	// cout<<maxn<<endl;
}


if(maxn < n){
	cout<<"NO"<<endl;
}
else{
	cout<<"YES"<<endl;

	queue<ll> que;
	que.push(1);
	ll to = 2;

	bool first = 1;

	while(!que.empty() && n>1){
		ll fr = que.front();
		que.pop();

		if(first){
			for(int i=1;i<=k && n>1;i++){
				que.push(to);
				cout<<fr<<' '<<to++<<'\n';
				n--;
			}
			first = 0;
		}
		else{
			for(int i=1;i<k && n>1;i++){
				que.push(to);
				cout<<fr<<' '<<to++<<'\n';
				n--;
			}
		}
	}
}
*/
