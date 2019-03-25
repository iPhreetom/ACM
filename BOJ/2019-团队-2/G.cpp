// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

//f[N]:可改变当前状态的方式，N为方式的种类，f[N]要在getSG之前先预处理
//SG[]:0~n的SG函数值
//S[]:为x后继状态的集合
vector<int> f[112345],sg[112345],s[112345];

void  getSG(int index, int n){
    int i,j;

	sg[index].resize(f[index].size(), 0);
    //因为SG[0]始终等于0，所以i从1开始
    for(i = 1; i <= n; i++){
        //每一次都要将上一状态 的 后继集合 重置
		s[index].resize(f[index].size(), 0);

        for(j = 0; f[j] <= i && j <= f[j]; j++)
            S[SG[i-f[j]]] = 1;  //将后继状态的SG函数值进行标记
        for(j = 0;; j++) if(!S[j]){   //查询当前后继状态SG值中最小的非零值
            SG[i] = j;
            break;
        }
    }
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int p,k;
	cin >> p >> k;

	int tryit = 0;

	for (int i=1; i<=p; i++){
		int c;
		cin >> c;
		for (int j=1; j<=c; j++){
			int t; cin >> t;
			f[i].push_back(t);
		}
	}

	if(!tryit){
		cout << "Bob will win." << endl;
	}
	else {
		cout << "Alice can win." << endl;
	}
	return 0;
}
