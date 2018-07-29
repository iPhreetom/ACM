//前缀和 —— 基础
#include<bits/stdc++.h>
using namespace std;

long long prelis[200005];
long long book[200005];
long long be[200005];
long long ed[200005];
long long n,k,q;
long long a,b;
long long now=0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>q;

	for(long long i=0;i<n;i++){
		cin>>a>>b;
		be[a]++;
		ed[b]++;
	}


	for(long long i=1;i<=200000;i++){
		now += be[i];

		if(now >= k){
			book[i]=1;
		}

		prelis[i] += book[i];
		prelis[i] += prelis[i-1];

		now -= ed[i];
	}


	for(long long i=0;i<q;i++){
		cin>>a>>b;
		cout<<prelis[b]-prelis[a-1]<<endl;
	}
	return 0;
}
