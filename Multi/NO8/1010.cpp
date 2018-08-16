#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int maxn = 100005;

vector<int> a(maxn); // val
vector<int> a1(maxn); // index
vector<pair<int,int> > a1v(maxn); // index
vector<int> a2[maxn]; // index -> val
int vis[maxn];
int n,q;
int len;

void init(){
	len = 0;
	a1[0] = 0;
	a[0] = 0;

	int mx = 0;

	// 得到最初的数组
	for (int i=1; i<=n; i++){
		if(a[i] > mx){
			a1[++len] = i;
			a1v[len] = make_pair(a[i],i);
		}
	}
	for (int i=1; i<=len; i++){
		vis[a1[i]] = len - i + 1;
	}
	a1[len+1] = a[len];

	// 在两个选定位置间，找到一个上升序列，以便于以后二分
	for (int i=1; i<len; i++){
		int tp = a[a1[i]-1];
		for (int j=a1[i]+1; j<a1[i+1]; j++){
			if(a[j] > tp){
				a2[i].push_back(a[j]);
			}
		}
	}

}

void clear_all(){
	for (int i=0; i<maxn; i++){
		a2[i].clear();
	}
	memset(vis,0,sizeof(vis));
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while (t--) {
		clear_all();

		cin>>n>>q;
		for (int i=1; i<=n; i++){
			cin>>a[i];
		}
		init();
		for (int i=0; i<q; i++){
		    int p,v;
			cin>>p>>v;
			if(v >= a[p]){
				// up();
				int last = lower_bound(a1.begin(),a1.begin()+len+1,p) - a1.begin();
				// cout<<"last = "<<last<<endl;
				if(a1[last] >= v || last == 0){
					cout<<len<<endl;
				}
				else{
					int past = upper_bound(a1v.begin()+last+2,a1v.begin()+len+1,make_pair(v,p)) - a1v.begin();

					cout<<(len - vis[last]) + 1 + vis[a1v[past].second]<<endl;
				}
			}
			else{ //  改小
				// down();
				if(vis[p]){
					int now = lower_bound(a1.begin(),a1.begin()+len+1,p) - a1.begin();

					int later = lower_bound(a1v.begin(),a1v.end(),make_pair(v,p)) - a1v.begin();

					cout<<vis[later];
				}
				else{
					cout<<len<<endl;
				}
			}
		}
	}
	return 0;
}
