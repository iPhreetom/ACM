//暴力枚举 -- 基础
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a;
	cin>>a;
	long long ans = 0;
	int n = a.size();
	for(int i=0;i<n-2;i++){
		if(a[i] == 'Q'){
			for(int j=i+1;j<n;j++){
				if(a[j] == 'A'){
					for(int k=j;k<n;k++){
						if(a[k] == 'Q')ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
