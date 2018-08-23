#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int maxn = 1e6+1e5;
// int sg[maxn];
// bool vis[28];
// int a[21];
// int pow2[26];
int sg2[1<<20],visit[21];

int getsg2(int sta)
{
    memset(visit,0,sizeof(visit));

    for(int i = 19 ; i > 0 ; i --)
    {
        if(sta & (1 << i))
        {
            for(int j = i - 1 ; j >= 0 ; j --)
            {
                if(sta & (1 << j))continue;
                int step = sta ^ ( 1 << i) ^ ( 1 << j);
                visit[sg2[step]] = 1;
                break;
            }
        }
    }
    //因为一个局面最多动20个棋子导致20个局面，所以sg2值一定小于等于20
    for(int i = 0 ; i <= 20 ; i ++)
        if(!visit[i]) return i;
    return 0;
}


int qmain()
{
    for(int i = 0 ; i < (1<<20) ; i ++)
        sg2[i] = getsg2(i);
}

// inline void move(int index){
// 	memset(vis,0,sizeof(vis));
// 	int num = index;
// 	for (int i=19; i>=0; i--){
// 	    if(a[i] == 1){
// 			for (int j=i-1; j>=0; j--){
// 				if(a[j] == 0){
// 					num -= pow2[i];
// 					num += pow2[j];
					// vis[sg[num]] = 1;
// 					break;
// 				}
// 			}
// 		}
// 	}
// 	int ans = 0;
// 	for (int i=0; i<22; i++){
// 		if(vis[i] == 1)ans++;
// 		else break;
// 	}
// 	sg[index] = ans;
// }

// void init(){
// 	pow2[0] = 1;
// 	for (int i=1; i<=25; i++){
// 		pow2[i] = pow2[i-1]*2;
// 	}
// 	for (int i=1; i<=maxn; i++){
// 		int t = i;
// 		for (int j=0; j<20; j++){
// 			a[j] = t%2;
// 			t/=2;
// 		}
// 		move(i);
// 	}
// }

void solve(){
	int n;
	cin>>n;
	int ans = 0;
	for (int i=0; i<n; i++){
		int num = 0;
		int m;cin>>m;
		for (int j=0; j<m; j++){
		    int p;cin>>p;
			num |= (int)pow(2,20-p);
		}
		ans ^= sg2[num];
	}
	if(ans){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// init();
	qmain();
	// for (int i=0; i<1e6; i++){
	//     if(sg[i] != sg2[i]){
	// 		cout<<"i = "<<i<<endl;
	// 		cout<<"sg[i] = "<<sg[i]<<endl;
	// 		cout<<"sg2[i] = "<<sg2[i]<<endl;
	// 		break;
	// 	}
	// }
	// for (int i=0; i<1e2; i++){
	//     cout<<sg[i]<<' ';
	// }cout<<endl;
	int tt;cin>>tt;
	while(tt--)solve();
	return 0;
}
