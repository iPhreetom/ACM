
#include<bits/stdc++.h>
using namespace std;


string a;
string b;
int ans = 0;
int ed,be;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;

	// 留意这个BUG
	int j = -1;
	for(int i=0;i<a.size();i++){
		for(j+=1;j<b.size();j++){
			if(a[i] == b[j]){
				if(i == a.size()-1)ed = j;
				break;
			}
		}
	}

	j = b.size();
	for(int i=a.size()-1;i>=0;i--){
		for(j-=1;j>=0;j--){
			if(a[i] == b[j] ){
				// cout<<j<<"-";
				if(i == 0)be = j;
				break;
			}
		}
	}

	// cout<<be<<' '<<ed<<endl;
	if(be <= ed){
		cout<<0<<endl;
	}
	else{
		cout<<be-ed<<endl;
	}
	return 0;
}
