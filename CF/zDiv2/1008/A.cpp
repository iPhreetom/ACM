#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	string  a;
	cin>>a;

	bool mas=0;
	for(int i=0;i<a.size();i++){
		if(mas){
			if(a[i] == 'a' || a[i] == 'o' || a[i] == 'u' || a[i] == 'i' || a[i] == 'e')
				mas = 0;
			else{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else{
			if(a[i] == 'a' || a[i] == 'o' || a[i] == 'u' || a[i] == 'i' || a[i] == 'e' || a[i] == 'n'){
				mas = 0;
			}
			else{
				mas = 1;
			}
		}
	}
	int i = a.size()-1;
	if(a[i] == 'a' || a[i] == 'o' || a[i] == 'u' || a[i] == 'i' || a[i] == 'e' || a[i] == 'n'){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}



	return 0;
}
