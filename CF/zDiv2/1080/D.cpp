// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int now[33];
int qq[33];
int digui(int index){
	if(index == 31)return qq[32-index] =  1;
	qq[32-index] = digui(index+1)*4;
	return qq[32-index];
}
void init(){
	qq[31] = digui(1);
	for (int i=1; i<=31; i++){
	    now[i] = now[i-1]+qq[i];
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init();
	int test;
	cin>>test;
	while(test--){
		vector<pair<int,int>> v;

		int n,k;
		cin>>n>>k;

		int path = n;
		int op = 1;
		bool can = 0;

		if(n >= 31){
			can = 1;
		}

		while(k >= op && path >= 1){
			path--;
			k -= op;
			op = op*2+1;
			v.push_back(make_pair(path,op-2));
		}

		if(can){
			cout<<"YES"<<' '<<path<<endl;
		}
		else{
			int res = 0;
			for (int i=0; i<v.size(); i++){
				if(res > 1e18		)break;
				res += now[v[i].first]*v[i].second;
			}

			if(res >= k){
				cout<<"YES"<<' '<<path<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
