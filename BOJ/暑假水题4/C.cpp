#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

string s[105];
int n;
int len;

bool check(int b,int l){
	for (int i=0; i<n-1; i++){
	    if(s[i].substr(b,l) > s[i+1].substr(b,l))return 0;
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>len;
	for (int i=0; i<n; i++){
	    cin>>s[i];
	}

	int indexlen=1;
	int index = 0;
	int cnt = 0;
	for (int q=0; q<len; q++){
		if(!check(0,indexlen)){
			for (int i=0; i<n; i++){
			    s[i].erase(index,1);
			}
			cnt++;
		}
		else{
			index++;
			indexlen++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
