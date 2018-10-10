#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct node{
	int n;
	vector<int> a;
};


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,t;
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		vector<set<int>> pro;
		int n,m;

		cin>>n>>m;
		for (int i=0; i<n; i++){
			int t;
			set<int> s;
			cin>>t;
			for (int i=0; i<t; i++){
				int tp;
				cin>>tp;
				s.insert(t);
			}
			pro.push_back(s);
		}

		for (int i=0; i<m; i++){
			int t;
			cin>>t;

		}

		cout<<"Case #"<<ii<<"	: "<<"\n";
	}
	return 0;
}
