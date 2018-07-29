
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin>>n>>s;

	bool ok=0;

	for(int i=0;i<n && !ok;i++){
		if(s[i] == '*'){
			for(int j=1;j<n && !ok;j++){
				for(int k=i,q=1;k<n && q<=5;k+=j,q++){
					if(s[k]!='*')break;
					else if(q == 5)ok=1;
				}
			}
		}
	}
	if(ok)cout<<"yes"<<endl;
	else cout<<"no"<<endl;

	return 0;
}
