#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,t;
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		int q;
		int x = 0;
		bool can = 0;
		string now;
		deque<string> que[6];
		set<string> wf;

		cin>>q;
		cin>>now;

		int y = q;
		for (int i=0; i<6; i++){
			for (int j=0; j<20; j++){
				string s;
				cin>>s;
				que[i].push_back(s);
			}
		}

		bool ct = 1;
		while(q && ct){
			for (int i=0;ct && q && i<5; i++){
				if(que[i].front() == now){
					ct = 0;
				}
				else{
					if(wf.count(que[i].front()) == 0){
						q--;
						y--;
						wf.insert(que[i].front());
					}
					que[i].pop_front();
				}
			}
		}

		while(q && !que[5].empty()){
			if(que[5].front() != now){
				if(wf.count(que[5].front()) == 0){
					q--;
					wf.insert(que[5].front());
				}
			}
			else{
				break;
			}
			que[5].pop_front();
		}

		if(q > 0){
			cout<<"Case #"<<ii<<": "<<"ADVANCED!"<<"\n";
		}
		else{
			cout<<"Case #"<<ii<<": "<<y<<"\n";
		}

	}
	return 0;
}
