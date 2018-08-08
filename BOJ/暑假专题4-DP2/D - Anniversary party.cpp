#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

priority_queue<int> que;
int mx ;
int mn ;
int now ;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n>>mx;
	for (int i=0; i<n; i++){
	    int l,r;
		cin>>l>>r;
		now += l;
		mn += r;
		que.push(l-r);
	}
	if(mn > mx){
		cout<<-1<<endl;
		return 0;
	}

	int cnt = 0;
	while(now > mx){
		now -= que.top();
		que.pop();
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
