// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> a;
// vector<int> b;
map<int,int> ans;
set<int> s;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,d;
	cin>>n>>m>>d;
	// d++;

	for (int i=0; i<n; i++){
	    int t;
		cin>>t;
		s.insert(t);
		a.push_back(t);
	}

	int num = 1;
	while(!s.empty()){
		int f = *s.begin();
		ans[f] = num;
		s.erase(f);

		f+=d;
		while(1){
			if(!s.empty() && s.upper_bound(f) != s.end()){
				f = *s.upper_bound(f);
				ans[f] = num;
				s.erase(f);
				f+=d;
			}
			else break;
		}
		num++;
	}

	cout<<num-1<<endl;
	for (int i=0; i<a.size(); i++){
	    cout<<ans[a[i]]<<' ';
	}cout<<endl;
	return 0;
}
