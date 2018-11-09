// 1043D
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int num[112345][10];
int mp[112345][10];

inline int getans(int &a){
	return (a+1)*(a)/2;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=m; i++){
	    for (int j=1; j<=n; j++){
			cin>>num[j][i];
			mp[ num[j][i] ][i] = j;
	    }
	}

	int sum = 0;
	int ans = 0;
	bool can = 1;

	for (int i=1; i<=n; i++){
		if(can == 0)can = 1;
		for(int j=2; j<=m; j++){
			int &now = mp[ num[i][1] ][j];
			int &nowlt = mp[ num[i-1][1] ][j];
			if(i!=1 && now-1 != nowlt)can = 0;
		}
		if(can == 0){
			ans += getans(s	um);
			sum = 1;
		}
		else{
			sum ++;
		}
	}
	ans += getans(sum);
	cout<<ans<<endl;
	return 0;
}
