#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 2e7+2;
vector<int> fre;
int a[maxn];
int cnt[maxn];

void init(){
	int sq = sqrt(maxn);
	fre.push_back(1);



	for(int i=0;i<fre.size();i++){
		for (int j=0; j<=i; j++){
            if(fre[i] * fre[j] >= maxn)break;

		    if(fre[i] == fre[j])cnt[fre[j]*fre[i]]++;
			else cnt[fre[j]*fre[i]]+=2;
		}
	}

	for(int i=1;i<maxn;i++){
		cnt[i] += cnt[i-1];
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<cnt[n]<<endl;
	}
	return 0;
}
