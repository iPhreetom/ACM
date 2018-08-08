#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

struct line{
	int l;
	int r;
	int s;
	line (){}
	line (int a,int b,int c){
		this->l = a;
		this->r = b;
		this->s = c;
	}
};

typedef pair<int,pair<int,pair<int,int> > > pii;
priority_queue<pii,vector<pii>,greater<pii> > que;
priority_queue<pii,vector<pii>,greater<pii> > que2;

int a[100];
bool conf[100];
vector<line> arr;
vector<pii> arr2;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int l,r,s;
		cin>>l>>r>>s;
		que.push(make_pair(r-l+1,make_pair(l,make_pair(r,s))));
		arr.push_back(line(l,r,s));
	}

	while(!que.empty()){
		auto t = que.top();
		que.pop();
		if(t.first == 1){
			t.second.first;
			conf[t.second.first] = 1;
			a[t.second.first] = t.second.second.second;
		}else{
			int l = t.second.first;
			int r = t.second.second.first;
			int s = t.second.second.second;

			int num = 0;
			int change = 0;
			for(int i=l;i<=r;i++){
				num += conf[i];
				change += a[i];
			}

			if(num == r-l+1){ // 可以确定的
				if(change % 2 != s){
					for(int i=l;i<=r;i++){
						if(conf[i] == 0){
							a[i] = 1;
							conf[i] = 1;
						}
					}
				}
			}
			else{
				que2.push(t);
				arr2.push_back(t);
			}
		}
	}

	int up = 0;
	for(int k=0;k<arr2.size();k++){
		auto t = arr2[k];
		int l = t.second.first;
		int r = t.second.second.first;
		int s = t.second.second.second;

		for(int i=r;i<=l;i++){
			if(conf[i] != 0){
				up--;
			}
		}
	}

	for(int i=1;i<=n;i++){
		i!=n?cout<<a[i]<<' ':cout<<a[i]<<endl;
	}
	return 0;
}
