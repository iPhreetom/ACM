// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 2123456;
bool prime[maxn+1];

void getprime(){
	for (int i=2; i<=maxn; i++){
		prime[i] = 1;
	}

	for (int i=2; i<=maxn; i++){
		if(prime[i]){
			for(int j = i+i; j <= maxn ; j+=i){
				prime[j] = 0;
			}
		}
	}
}

int isok(int q){
	int cnt = 0;
	int num = 1;
	while(num < q){
		num *= 2;
		cnt++;
	}
	if(num == q){
		return cnt;
	}
	else{
		return cnt+1;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	getprime();

	int n;
	cin>>n;
	if(n == 1){
		cout<<"1 0"<<endl;
		return 0;
	}

	int num = n;
	int op = 0;

	vector<pair<int,int>> v;
	for (int i=2; i<=n; i++){
		if(prime[i] && (n % i == 0)){
			int cnt = 0;
			while(n && (n % i == 0)){
				n /= i;
				cnt++;
			}
			v.push_back(make_pair(i,cnt));
		}
	}
	if(v.size() == 1){
		cout<<v.back().first<<' ';
		cout<<isok(v.back().second)<<endl;
	}
	else{
		int sum = 1;
		int mx = 0;
		for (int i=0; i<v.size(); i++){
			// cout<<"v[i].first = "<<v[i].first<<endl;
			// cout<<"v[i].scecond = "<<v[i].second<<endl;
			mx = max(v[i].second,mx);
			sum *= v[i].first;
		}
		cout<<sum<<' ';

		bool same = 1;
		for (int i=1; i<v.size(); i++){
			if(v[i].second != v[i-1].second){
				same = 0;
			}
		}
		if(same){
			cout<<isok(mx)<<endl;
		}
		else{
			if(pow(2,isok(mx)) == mx){
				cout<<isok(mx)+1<<endl;
			}
			else{
				cout<<isok(mx)<<endl;
			}
		}
	}
	return 0;
}
