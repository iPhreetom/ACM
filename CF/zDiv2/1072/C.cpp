// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int lis[212345];
int lisb[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b;
	cin>>a>>b;

	int cnt = 0;
	int mx = 0;
	for (int i=1; i<=1e9; i++){
		if(a >= i){
			a -= i;
			lis[i] = i;
			cnt++;
			mx = i;
		}
		else break;
	}

	int mn = mx+1;
	for(int i=cnt;i>=1;i--){
		if(a > 0){
			mn = lis[i];
			lis[i]++;
			mx = max(mx,lis[i]);
			a--;
		}
		else{
			break;
		}
	}


	// b
	int index = 0;
	if(b >= mn){
		b -= mn;
		index++;
		lisb[index] = mn;
		for (int i=max(mn+1,mx+1); i<=1e9; i++){
			if(b>=i){
				b-=i;
				index++;
				lisb[index]=i;
			}
			else{
				break;
			}
		}
	}

	cout<<cnt<<endl;
	for (int i=1; i<=cnt; i++){
		cout<<lis[i]<<' ';
	}
	cout<<endl;
	cout<<index<<endl;
	for (int i=1; i<=index; i++){
		cout<<lisb[i]<<' ';
	}
	cout<<endl;
	return 0;
}
