// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int a[212345][3];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	string s;
	cin>>n;
	cin>>s;

	int cnt = 0;
	int mx = 0;
	int num = 0;
	int l = -1;
	int r = 0;
	int index = 0;

	for (int i=0; i<n; i++){
		if(s[i] == 'G'){
			if(l == -1){
				l = i;
			}
			cnt++;
		}
		else{
			if(cnt != 0){
				r = i-1;
				int len = r-l+1;
				a[++index][0] = l;
				a[index][1] = r;
				a[index][2] = len;
				l = -1;

				mx = max(cnt,mx);
				num++;
				cnt = 0;
			}
		}

		if(i == n-1 && s[i] == 'G'){
			r = i;
			int len = r-l+1;
			a[++index][0] = l;
			a[index][1] = r;
			a[index][2] = len;

			mx = max(mx,cnt);
			num++;
			cnt = 0;
		}
	}

	if(num <= 1){
		cout<<mx<<endl;
	}
	else{
		for(int i=2; i<=index; i++){
			if(a[i][0] == a[i-1][1]+2){
				if(num >= 3){
					mx = max(mx,a[i][2] + a[i-1][2] + 1);
				}
				else{
					mx = max(mx,a[i][2] + a[i-1][2]);
				}
			}
			else{
				if(num >= 2){
					mx = max(mx,max(a[i][2],a[i-1][2])+1);
				}
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}
