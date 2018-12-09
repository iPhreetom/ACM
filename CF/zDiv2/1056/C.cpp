// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int a[212345];
map<int,int> mp;
set<int> chose;
set<int> p;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=2*n; i++){
		cin>>a[i];
	}
	for (int i=1; i<=m; i++){
		int l,r;
		cin>>l>>r;
		mp[l] = r;
		mp[r] = l;
	}

	int tp = 0;
	cin>>tp;
	if(tp == 1){
		for (int j=1; j<=n; j++){
			if(mp.empty()){
				int mx = 0;
				int index = -1;
				for (int i=1; i<=2*n; i++){
					if(chose.count(i) == 0){
						if(a[i] > mx){
							mx = a[i];
							index = i;
						}
					}
				}
				cout<<index<<endl;
				chose.insert(index);
			}
			else{
				const int &f = mp.begin()->first;
				const int &s = mp.begin()->second;
				if(a[f] > a[s]){
					cout<<f<<endl;
				}
				else{
					cout<<s<<endl;
				}
				chose.insert(s);
				chose.insert(f);
				mp.erase(f);
				mp.erase(s);
			}
			int he;
			cin>>he;
			chose.insert(he);
		}
	}
	else{// tp = 2;
		for (int j=1; j<=n; j++){
			int he;
			cin>>he;
			chose.insert(he);

			if(mp.count(he) != 0){
				cout<<mp[he]<<endl;
				chose.insert(mp[he]);
				mp.erase(mp[he]);
				mp.erase(he);
			}
			else{
				if(mp.empty()){
					int mx = 0;
					int index = -1;
					for (int i=1; i<=2*n; i++){
						if(chose.count(i) == 0){
							if(a[i] > mx){
								mx = a[i];
								index = i;
							}
						}
					}
					cout<<index<<endl;
					chose.insert(index);
				}
				else{
					const int &f = mp.begin()->first;
					const int &s = mp.begin()->second;
					if(a[f] > a[s]){
						cout<<f<<endl;
					}
					else{
						cout<<s<<endl;
					}
					chose.insert(s);
					chose.insert(f);
					mp.erase(f);
					mp.erase(s);
				}
			}
		}
	}
	return 0;
}
