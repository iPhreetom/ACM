#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int n;
string s;

string ans[3];
string ans2[3];
int cnt[3] = {0};
int cnt2[3] = {0};
char ch[3] = {'R','G','B'};
char ch2[3] = {'R','B','G'};

int index = 1;
int index2 = 1;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	cin>>s;

	for (int i=0; i<n; i++){
		for (int j=0; j<3; j++){
			ans[j].push_back(ch[(++index)%3]);
			if(ans[j][i] != s[i])cnt[j] ++;
		}
		index++;
		index%=3;
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<3; j++){
			ans2[j].push_back(ch2[(++index2)%3]);
			if(ans2[j][i] != s[i])cnt2[j] ++;
		}
		index2++;
		index2%=3;
	}

	int mn = 1e9;
	for (int i=0; i<3; i++){
	    mn = min(mn,cnt[i]);
	}
	for (int i=0; i<3; i++){
	    mn = min(mn,cnt2[i]);
	}
	for (int i=0; i<3; i++){
	    if(cnt[i] == mn) {
			cout<<cnt[i]<<endl;
			cout<<ans[i]<<endl;
			return 0;
		}
	}
	for (int i=0; i<3; i++){
	    if(cnt2[i] == mn) {
			cout<<cnt2[i]<<endl;
			cout<<ans2[i]<<endl;
			break;
		}
	}

	return 0;
}
