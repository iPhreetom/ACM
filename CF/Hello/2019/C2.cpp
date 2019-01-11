// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int lcount[500005];
int rcount[500005];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int out = 0;

	while(n--){
		bool ok = 1;
		string s;
		cin>>s;

		int left = 0;
		int right = 0;
		for (int i=0; i<s.size(); i++){
			if(s[i] == '(') {
				left++;
			}
			else{
				if(left > 0){
					left -- ;
				}
				else{
					right++;
				}
			}
		}

		if(left > 0 && right > 0) {
			ok = 0;
		}
		if(ok) {
			int num = (left - right);
			if(num < 0)rcount[-num]++;
			else lcount[num] ++;
		}

	}

	out += lcount[0]/2;
	for (int i=1; i<=500004; i++){
		out += min(lcount[i],rcount[i]);
	}
	cout<<out<<endl;
	return 0;
}
