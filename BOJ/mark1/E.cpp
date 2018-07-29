#include<bits/stdc++.h>
using namespace std;

queue<long long> m;
queue<long long> f;
queue<long long> tque;
queue<char> ans;
long long n,k,t;

void solve(){
	long long first,sum;

	while(!f.empty()){
		sum = 0;
		first = f.front();
		f.pop();

		t = m.front();
		sum += t;

		if(sum > first){
			cout<<"NO"<<endl;
			return;
		}

		if(sum == first){
			if(tque.empty()){
				continue;
			}
			else{

			}
			continue;
		}

		if(sum < first){
			tque.push(t);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>t;
		m.push(t);
	}
	cin>>k;
	for(long long i=0;i<k;i++){
		cin>>t;
		f.push(t);
	}

	solve();
	return 0;
}
