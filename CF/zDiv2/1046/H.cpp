// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string s;
vector<bitset<26>> a[27];
unordered_map<bitset<26>,int> mp;
bitset<26> one;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	for (int i=1; i<=n; i++){
		cin>>s;
		bitset<26> tp;

		for (int j=0; j<s.size(); j++){
			one[s[j]-'a'] = 1;
			tp ^= one;
			one[s[j]-'a'] = 0;
		}

		// cout<<"tp = "<<tp<<endl;
		if(mp.count(tp)==0)a[tp.count()].push_back(tp);
		mp[tp]++;
	}

	bitset<26> tp;
	int sum = mp[tp]*(mp[tp]-1)/2;

	for (int i=1; i<27; i++){
		for(int k=0;k<a[i].size();k++){
			int sum1 = 0;
			int sum2 = 0;

			sum += mp[a[i][k]]*(mp[a[i][k]]-1)/2;
			for (int j=0; j<a[i-1].size(); j++){
				if((a[i][k] ^ a[i-1][j]).count() <= 1){
					sum1 += mp[a[i][k]]*mp[a[i-1][j]];
				}
			}

			for (int j=0; j<a[i].size(); j++){
				if(j == k)continue;
				if((a[i][k] ^ a[i][j]).count() <= 1){
					sum2 += mp[a[i][k]]*mp[a[i][j]];
				}
			}

			sum += sum1 + sum2/2;
		}
	}

	cout<<sum<<endl;
	return 0;
}
