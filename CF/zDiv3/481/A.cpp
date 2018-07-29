
#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
int a[1222];
bool book[1222];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i];
		book[a[i]]= 1;
	}
	for(int i=n-1;i>=0;i--){
		if(book[a[i]] == 1)ans.push_back(a[i]),book[a[i]]=0;
	}
	cout<<ans.size()<<endl;
	for(int i=ans.size()-1;i>=0;i--){
		if(i!=0){
			cout<<ans[i]<<' ';
		}
		else cout<<ans[i]<<endl;
	}
	//CF忽略多余的空格

	return 0;
}
