#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> arr;

int ans = 0;
int n;
int l;
int a[21];

void digui(int index,int v){
	if(index == n){ans++;return ;}
	if(v + a[index] <= l){
		digui(index+1,v+a[index]);
		digui(index+1,v);
	}
	else{
		digui(index+1,v);
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>l;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);

	digui(0,0);
	cout<<ans<<endl;
	return 0;
}
