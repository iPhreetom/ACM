// fyt
#include<bits/stdc++.h>
#include <time.h>
// #define int long long
// #define double long double
#define endl '\n'
using namespace std;


signed main(){
	// ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	double start,finish; /* 开始时间,结束时间 */
	start=(double)clock(); /* 我的time.h内没有CLOCKS_PER_SEC */
	vector<vector<int>> ans;
	for (int k=8; k<=10  ; k++){
		vector<pair<vector<int>,vector<int>>> v;
		vector<int> tmp;
		for (int j=1; j<=k; j++){
			tmp.push_back(j);
		}
		do{
			// if ((tmp[0] == 9 && (tmp[1]==1||tmp[1]==2)) || (tmp[0]==8&&tmp[1]==1));
			// else continue;
			// if (k==9 && tmp[0] == 7)break;
			vector<int> dif;
			for (int i=0; i<tmp.size()-1; i++){
				dif.push_back(tmp[i+1]-tmp[i]);
			}
			v.push_back(make_pair(dif,tmp));
		}while(next_permutation(tmp.begin(),tmp.end()));
		sort(v.begin(),v.end());

		cout<<"k = "<<k<<endl;
		cout<<"v.size() = "<<v.size()<<endl;
		if (k>=8){
			for (int j=0; j<v[10000-1].first.size(); j++){
				cout << v[10000-1].first[j] << ' ';
			}cout << endl;
			for (int j=0; j<v[10000-1].second.size(); j++){
				cout << v[10000-1].second[j] << ' ';
			}cout << endl;
		}

		for (int i=0; i<min((int)v.size(),20); i++){
			// for (int j=0; j<v[i].first.size(); j++){
				// 	cout << v[i].first[j] << ' ';
				// }cout << endl;
			for (int j=0; j<v[i].second.size(); j++){
				cout << v[i].second[j] << ' ';
			}cout << endl;
		}
		cout << "____" << endl;

	}
	finish=(double)clock();
	printf("%.4fms",(finish-start) );
	return 0;
}
