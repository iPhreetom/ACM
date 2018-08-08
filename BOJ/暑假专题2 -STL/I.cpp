#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		stack<int> stk;
		queue<int> que;
		priority_queue<int> pque;

		bool f=1,s=1,t=1;
		bool wa = 0;
		for(int i=0;i<n;i++){
			int q,v;
			cin>>q>>v;
			if(q == 1){
				stk.push(v);
				que.push(v);
				pque.push(v);
			}
			else{
				if(stk.empty()){
					wa = 1;
					continue;
				}

				if(v != stk.top())f=0;
				if(v != que.front())s=0;
				if(v != pque.top())t=0;
				stk.pop();
				que.pop();
				pque.pop();
			}
		}

		if(wa){
			cout<<"impossible"<<endl;
			continue;
		}

		int sum = (int)f + s + t;

		if(sum >= 2){
			cout<<"not sure"<<endl;
		}else if(sum == 0){
			cout<<"impossible"<<endl;
		}else if(f){
			cout<<"stack"<<endl;
		}else if(s){
			cout<<"queue"<<endl;
		}else if(t){
			cout<<"priority queue"<<endl;
		}
	}
	return 0;
}
