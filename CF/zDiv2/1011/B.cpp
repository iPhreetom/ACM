#include<bits/stdc++.h>
#define int long long
#define double long double
#define make(a,b) make_pair(a,b)
using namespace std;


vector<int> arr;
vector<int> arrt;

map<int,int> mp;
int n,m;

bool cant(int d){
	int solve = 0;
	int index = 0;
	while(solve<n){
		if(index == arr.size()){
			return true;
		}

		if(arr[index] >= d){
			arr[index]-=d;
			solve++;
		}
		else{
			index++;
		}

	}
	return false;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		mp[t]++;
	}

	for(auto i:mp){
		arr.push_back(i.second);
	}
	sort(arr.begin(),arr.end());

	arrt = arr;
	for(int i=1;;i++){
		if(cant(i)){
			cout<<i-1<<endl;
			break;
		}
		arr = arrt;
	}
	return 0;
}
