// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	vector< pair<vector<int>,vector<int>> > ans[21];
	for (int k=1; k<=9; k++){
		vector<pair<vector<int>,vector<int>>> v;
		vector<int> tmp;
		for (int j=1; j<=k; j++){
			tmp.push_back(j);
		}
		do{
			vector<int> dif;
			for (int i=0; i<tmp.size()-1; i++){
				dif.push_back(tmp[i+1]-tmp[i]);
			}
			v.push_back(make_pair(dif,tmp));
		}while(next_permutation(tmp.begin(),tmp.end()));
		sort(v.begin(),v.end());
		swap(ans[k],v);
	}

	// 10
	vector<pair<vector<int>,vector<int>>> v;
	vector<int> tmp;
	for (int j=2; j<=9; j++){
		tmp.push_back(j);
	}
	do{
		vector<int> tt;
		tt.push_back(1);
		for (int j=0; j<tmp.size(); j++){
			tt.push_back(tmp[j]);
		}
		vector<int> dif;
		for (int i=0; i<tt.size()-1; i++){
			dif.push_back(tt[i+1]-tt[i]);
		}
		v.push_back(make_pair(dif,tt));
	}while(next_permutation(tmp.begin(),tmp.end()));
	sort(v.begin(),v.end());
	swap(ans[10],v);


	int T;
	cin >> T;
	while(T--){
		int n,k;
		cin >> n >> k;
		if (n <= 9) {
			bool f = 1;
			for (int i=0; i<ans[n][k-1].second.size(); i++){
				if (f) cout << ans[n][k-1].second[i],f = 0;
				else cout << ' ' << ans[n][k-1].second[i];
			}
			cout << endl;
		}
		else {
			cout << n;
			int add = n-10;
			for (int i=1; i<n-9; i++){
				cout << ' ' << i;
			}
			for (int i=0; i<ans[10][k-1].second.size(); i++){
				cout << ' ' << add+ans[10][k-1].second[i];
			}
			cout << endl;
		}
	}
	return 0;
}
