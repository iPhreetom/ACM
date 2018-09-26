// genius
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int MOD = 1e9 + 7;
int mi;
char x[10][105];
int cnt[10];
int ans;
bool use[105];
void init()
{
	mi = 1;
	for(int i = 1; i <= 15;i ++)
	    mi *= 96 - i , mi %= MOD;
	// for(int i = 1; i <= 5;i ++)
	//     mi *= 96	 - i , mi %= MOD;

	// for(int k=100;k>=1;k--){
	// 	for (int j=1; j<=100; j++){
	// 		mi = 1;
	// 		for(int i = 0; i <= j;i ++){
	// 			mi *= (k - i) ;
	// 			mi %= MOD;
	// 		}
	// 		if(mi == 531192758)cout<<"mi = "<<mi<<endl;
	// 	}
	// }

	cout<<"SD"<<endl;
}

void force(int now)
{
	//cout << now <<endl;
	if(now == 5)
	{
		ans += cnt[5];
		if(ans >= MOD) ans -= MOD;
		return ;
	}
	for(int i = 0; i < 100; i++)
	{
		if(x[now][i] == '1' && !use[i])
		{
			use[i] = 1;
			x[5][i]--;
			if(x[5][i] == '0')
			    cnt[5]--;

			force(now + 1);

			use[i] = 0;
			x[5][i]++;
			if(x[5][i] == '1')
			    cnt[5]++;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    init();
	while(cin >> x[1] >> x[2] >> x[3] >> x[4] >> x[5])
	{
		memset(cnt, 0, sizeof cnt);
		memset(use, 0, sizeof use);
		ans = 0;
		for(int i = 1; i <= 5;i ++)
		{
			for(int j = 0; j < 100; j++)
			    if(x[i][j] == '1')
				{
					cnt[i] ++;
				//	a[i][j] = 1;
				}
				//else
				//    a[i][j] = 0;
		}
		force(1);
		ans = (ans * mi) % MOD;
		cout << ans << endl;
	}
	return 0;
}
