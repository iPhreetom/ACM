#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<int,vector<int>,greater<int> > que;
int a[2123];
int book[2123];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	for(int i=1;i<=n*2;i++){
		cin>>a[i];
		if(book[a[i]]){
			que.push(i);
		}
		else{
			book[a[i]]=1;
		}
	}
	int num = 0;
	int ans = 0;
	// cout<<que.top()<<endl;
	while(!que.empty()){
		num = a[que.top()];
		for(int i=que.top();i>0;i--){
			if(a[i-1]!=num){
				swap(a[i-1],a[i]);
				ans++;
			}
			else{
				break;
			}
		}
		que.pop();
	}
	cout<<ans<<endl;

	return 0;
}
