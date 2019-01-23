#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int n,k;
string s;
int ans[26];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	cin>>s;
	char ch = 'A';
	int cnt = 0;
	while(!s.empty()) {
		if(s.back() == ch) {
			cnt++;
		}
		else {
			cnt = 1;
			ch = s.back();
		}
		if(cnt == k) {
			ans[s.back()-'a']++;
			ch = 'A';
			cnt = 0;
		}
		s.pop_back();
	}

	int mn = 0;
	for (int i=0; i<26; i++){
		mn = max(mn,ans[i]);
	}
	cout<<mn<<endl;
	return 0;
}
