#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool prime[9999991];
void init(){
	memset(prime,1,sizeof(prime));
	// for(int i=0;i<9999991;i++)prime[i]=1;
	for(int i=2;i*i<9999991;i++){
		if(prime[i]){
			for(int j=i*2;j<9999991;j+=i){
				prime[j]=0;
			}
		}
	}
}

int find(int n){
	int ans=0;
	for(int i=2;i<=n;i++){
		if(prime[i])ans++;
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	int n;
	while(cin>>n){
		cout<<find(n)<<endl;
	}
	return 0;
}
