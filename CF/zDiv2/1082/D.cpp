// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];
int one = 0;
int sum = 0;
priority_queue<pair<int,int> > que;
stack<int> st;
int n;
int cnt = 0;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++){
		int t;
		cin>>t;
		if(t == 1) one++;
		else cnt++, sum += t;
		a[i] = t;
	}

	if(cnt >= 2)sum-=2;
	sum -= 2*(max(cnt-2,0ll));

	if(sum < one){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<' ';

		if(one >= 2){
			cout<<n-one+1<<endl;
		}
		else{
			cout<<n-1<<endl;
		}
		cout<<n-1<<endl;

		// 输出方案
		for (int i=1; i<=n; i++){
			if(a[i] == 1){
				st.push(i);
			}
			else{
				que.push(make_pair(a[i],i));
			}
		}
		//
		int ls = -1;
		bool first = 1;
		bool only = 0;
		if(que.size() == 1){
			only = 1;
		}
		while(!que.empty()){
			int val = que.top().first;
			int now = que.top().second;
			que.pop();
			if(only){
				while(!st.empty()){
					cout<<now<<' '<<st.top()<<endl;
					val--;
					st.pop();
				}
			}
			else{
				if(first){
					first = 0;
					val--;
				}
				else{
					if(que.empty()){
						val--;
					}
					else{
						val -= 2;
					}
				}
				while( (st.size()>1 || (!st.empty() && que.empty())) && val > 0){
					cout<<now<<' '<<st.top()<<endl;
					val--;
					st.pop();
				}
				if(ls != -1){
					cout<<ls<<' '<<now<<endl;
					ls = now;
				}
				else ls = now;
			}
		}
	}
	return 0;
}
