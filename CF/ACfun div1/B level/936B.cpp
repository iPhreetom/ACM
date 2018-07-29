#include<bits/stdc++.h>
using namespace std;
// typedef long long int;

vector<vector<int> > mp;
int n,m;
int book[212345];
bool d=0;
// set<int> win;
int be;
// vector<int> ans;
vector<int> win;
bool findd = 0;

struct node{
	int id=0;
	int past=0;
	int past2=0;
	bool re=0;
};

node arr[212345];

void bfs(node p,int dp,int fr){
	if(findd)return ;
	cout<<p.id<<endl;

	int index = p.id;
	node tp;
	if(mp[index].size()==0){
		// ans.push_back(dp);
		if(dp % 2 == 0){
			findd = 1;
			node poi = p;
			while(poi.past != 0 || poi.past2 != 0){
				// cout<<"??"<<endl;
				if(poi.re==0){
					win.push_back(poi.id);
					int last = arr[poi.id].past;
					poi = arr[last];
				}
				else {
					win.push_back(poi.id);
					// win.push_back(poi.id);
					arr[poi.id].re=0;
					int last = arr[poi.id].past2;
					// arr[poi.id].past = arr[poi.id].past2;
					arr[poi.id].past2 = 0;
					poi = arr[last];
				}
			}
		}
		return;
	}

	for(int i=0;i<mp[index].size();i++){
		if(index == 4){
			// cout<<"????"<<endl;
		}
		if(book[mp[index][i]] != 0){
			d=1;
			if(book[mp[index][i]] != -1 && dp % 2 != book[mp[index][i]]%2){
				int t1,t2;
				t1 = book[mp[index][i]];
				t2 = arr[tp.id].past;

				book[mp[index][i]]=-1;
				tp.id = mp[index][i];
				tp.past2 = p.past;
				tp.past = arr[tp.id].past;
				tp.re = 1;

				arr[tp.id]=tp;
				bfs(tp,dp+1,index);
				book[mp[index][i]]=t1;

				node recover;
				recover.past = t2;
				arr[mp[index][i]]=recover;
			}
			else{
				continue;
			}
		}
		else{// book == 0
			book[mp[index][i]]=dp;
			tp.id = mp[index][i];
			tp.past = index;
			tp.re = 0;
			arr[tp.id]=tp;
			bfs(tp,dp+1,index);
			book[mp[index][i]]=0;
			node recover;
			arr[mp[index][i]]  = recover;
		}
	}
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m;
	mp.resize(n+1);

	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=0;j<t;j++){
			int to;
			cin>>to;
			mp[i].push_back(to);
		}
	}

	cin>>be;

	book[be]=1;
	node tp;
	tp.id = be;
	tp.past = 0;
	tp.re=0;
	cout<<"________________"<<endl;
	bfs(tp,1,0);

	if(win.size()!=0){
		cout<<"Win"<<endl;
		cout<<be<<' ';
		for(int i=win.size()-1;i>=0;i--){
			cout<<win[i]<<' ';
		}cout<<endl;
		return 0;
	}
	else{
		if(d)cout<<"Draw"<<endl;
		else cout<<"Lose"<<endl;
		return 0;
	}

	// if(ans.size()==0){
	// 	if(d)cout<<"Draw"<<endl;
	// 	else cout<<"Lose"<<endl;
	// }
	// else{
	// 	for(int i=0;i<ans.size();i++){
	// 		if(ans[i]%2 == 0){
	// 			cout<<"Win"<<endl;
	// 			// find(ans[i]);
	// 			return 0;
	// 		}
	// 	}
	// 	if(d)cout<<"Draw"<<endl;
	// 	else cout<<"Lose"<<endl;
	// }

	return 0;
}
