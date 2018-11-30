// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

int n,c;
int a[512345];
int p[512345];
int index[512345];
int ended[512345];
int arr[512345];
int mx = 0;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>c;
	memset(index,0,sizeof(index));
	for (int i=1; i<=n; i++){
		int t;
		cin>>t;
		arr[i] = t;
		p[i] = p[i-1];
		if(t == c){
			p[i]++;
			mx = max(mx,p[i]);
		}
	}
	for (int i=1; i<=n; i++){
		int t = arr[i];
		if(t != c){
			if(index[t] == 0){
				index[t] = i;
				ended[t] = i;
				a[t] = 1;
				mx = max(mx , p[index[t]] + a[t] + (p[n] - p[ended[t]]));
			}
			else{
				// not add yet
				if(a[t] - (p[i] - p[index[t]]) <= 0){
					index[t] = i;
					ended[t] = i;
					a[t] = 1;
					mx = max(mx , p[index[t]] + a[t] + (p[n] - p[ended[t]]));
				}
				else{
					a[t]++;
					ended[t] = i;
					mx = max(mx , p[index[t]] + a[t] + (p[n] - p[ended[t]]));
				}
			}
		}
	}

	cout<<mx<<endl;
	return 0;
}
