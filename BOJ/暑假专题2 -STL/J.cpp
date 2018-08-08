#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

deque<string> que;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	string s;
	while(cin>>s){
		bool front = 1;
		string t;

		for(int i=0;i<s.size();i++){
			if(s[i] == ']' || s[i] == '['){
				if(front && !t.empty()){
					que.push_front(t);
				}
				if(!front && !t.empty()){
					que.push_back(t);
				}
				if(s[i] == ']')front = 0;
				else front = 1;
				t.clear();
			}else{
				t.push_back(s[i]);
			}
		}

		if(front && !t.empty()){
			que.push_front(t);
		}
		if(!front && !t.empty()){
			que.push_back(t);
		}

		
		while(!que.empty()){
			cout<<que.front();
			que.pop_front();
		}
		cout<<endl;
	}
	return 0;
}
