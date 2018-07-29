#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

	string a,b;
	int ans = 0;
	cin>>a>>b;
	if(a.size() < b.size()){
		cout<<0<<endl;
	}
	else{
		for(int i=0;i<a.size()-b.size()+1;i++){
			if(a[i] == b[0]){
				for(int j=0;j<b.size() && i<a.size();j++){
					if(a[i+j]!=b[j]){
						// i--;
						break;
					}
					else {
						// i++;
						if(j == b.size()-1){
							// i--;
							a[i+j] = '#';
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}

    return 0;
}
