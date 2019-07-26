#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<vector>
#include<queue>
using namespace std;
const int maxl = 10000;
bool prime[maxl];

int be;
int dp[10000];

bool cmp(int a,int b){
	int dif=0;
	for(int i=0;i<4;i++){
		if(a%10 != b%10)dif++;
		a/=10;
		b/=10;
	}
	if(dif == 1)return 1;
	else return 0;
}

int find(int a,int b){
	if(dp[a])return dp[a];
	else dp[a] = 99999;

	for(int i=a+1;i<maxl;i++){
		if(prime[i]){
			if(i==b && cmp(i,a)){
				dp[a] = 1;
				continue;
			}
			if(cmp(i,a)){
				// cout<<i<<finl;
				dp[a] = min(find(i,b)+1,dp[a]);
			}
		}
	}

	for(int i=a-1;i>=1000;i--){
		if(prime[i] && !dp[i]){
			if(i==b && cmp(i,a)){
				dp[a] = 1;
				continue;
			}
			if(cmp(i,a)){
				dp[a] = min(find(i,b)+1,dp[a]);
			}
		}
	}
	// cout<<dp[a]<<finl;
	return dp[a];
}

set<int> se;
vector<int> ve;
queue<int> que1;
queue<int> que2;
int a,b,n;
bool fin = 0;

void init(){
	for(int i=0;i<maxl;i++)prime[i]=1;
	for(int i=2;i*i<maxl;i++){
		if(prime[i]){
			for(int j=i*2;j<maxl;j+=i){
				prime[j]=0;
			}
		}
	}
	for(int i=1000;i<maxl;i++){
		if(prime[i])ve.push_back(i);
	}
}

void search1(int n){
	for(int i=0;i<ve.size();i++){
		if(se.count(ve[i])==0 && cmp(ve[i],n)){
			if(ve[i] == a)fin = 1;
			que1.push(ve[i]);
			se.insert(ve[i]);
		}
		//距离为1的数字
	}
}

void search2(int n){
	for(int i=0;i!=ve.size();i++){
		if(se.count(ve[i])==0 && cmp(ve[i],n)){
			if(ve[i] == a)fin = 1;
			que2.push(ve[i]);
			se.insert(ve[i]);
		}
		//距离为1的数字
	}
}

void bfs(){
	search1(b);
	bool que = 1;
	int ans=1;

	while(!fin && !que1.empty() || !que2.empty()){
		// && || 的关系太强啦
		// printf("ans: %d\n",ans);
		if(que){
			int tp;
			while(!que1.empty()){
				tp = que1.front();
				que1.pop();
				search2(tp);
			}
			ans++;
			que = !que;
		}
		else{
			int tp;
			while(!que2.empty()){
				tp = que2.front();
				que2.pop();
				search1(tp);
			}
			ans++;
			que = !que;
		}
	}
	if(fin == 0){
		cout<<"Impossible"<<endl;
	}
	else{
		cout<<ans<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin>>n;
	while(n--){
		// memset(dp,0,sizeof(dp));
		cin>>a>>b;
		se.clear();
		while(!que1.empty())que1.pop();
		while(!que2.empty())que2.pop();
		fin = 0;
		be = min(a,b);
		b = max(a,b);
		a = be;
		if(prime[a] && prime[b]){
			if(a == b)cout<<0<<endl;
			else{
				bfs();
			}
		}
		else{
			cout<<"Impossible"<<endl;
		}
	}

	// bfs();
	// cout<<"___________"<<endl;
	// for(int i=0;i<maxl;i++){
	// 	if(dp[i] == 1)cout<<i<<endl;
	// }
	// cout<<"____________"<<endl;
	// for(int i=1000;i<maxl;i++){
	// 	if(prime[i] && cmp(i,b)){
	// 		cout<<i<<endl;
	// 	}
	// }
	// cout<<endl<<finl;
	//
	//

	return 0;
}
