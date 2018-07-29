#include<bits/stdc++.h>
#define int long long
#define double long double
#define make(a,b) make_pair(a,b)
using namespace std;


vector<int> arr;
int n,d,k;
int maxn;
int to = 2;
int from = 1;

void dfs(int dp,int out,int trunk){
	if(arr.size() > 8e5)return ;


}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>d>>k;
	if(n<d){
		cout<<"NO"<<endl;
		return 0;
	}

	
	cout<<arr.size()/2<<endl;
	for(int i=0;i<arr.size();i+=2){
		cout<<arr[i]<<' '<<arr[i+1]<<endl;
	}
	return 0;
}
