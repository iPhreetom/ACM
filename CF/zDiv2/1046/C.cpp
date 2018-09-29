// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[2123456];
int b[2123456];
// bool vis[2123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,d;
	cin>>n>>d;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	for (int i=1; i<=n; i++){
	    cin>>b[i];
	}
	int now = a[d];
	now += b[1];
	// vis[1] = 1;

	if(d == 1){
		cout<<1<<endl;
	}
	else{
		int index = d-1;
		int point = -1;
		if(a[index] + b[n] > now){
			cout<<d<<endl;
		}
		else{
			// find point
			for(int i=n;i>=2;i--){
				if(a[index] + b[i] >= now){
					point = i;
					break;
				}
			}

			// if find 2
			if(point == -1)point = 2;
			bool end = 0;
			int sum = 0;

			// 5 4 3 2 1
			// 5 4 3 2 1
			// cout<<"point = "<<point<<endl;
			while(!end && index != 0 && point <= n){
				while(!end && a[index] + b[point] > now){
					point++;
					if(point == n+1){
						end = 1;
					}
				}
				if(!end){
					index--;
					point++;
					sum++;
				}
			}
			cout<<d-sum<<endl;
		}
	}

	return 0;
}
