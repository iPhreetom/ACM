#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string a;
	cin>>n>>a;
	string tp1,tp2,ans;

	int mx = 0;
	int tn = 0;
	for(int i=0;i<n-2;i++){
		tp1.clear();tn=0;

		tp1.push_back(a[i]);
		tp1.push_back(a[i+1]);

		for(int j=0;j<n-1;j++){
			if(a[j] == tp1[0] && a[j+1] == tp1[1]){
				tn++;
			}
		}
		if(tn > mx){
			mx = tn;
			ans = tp1;
		}
	}

	if(n == 2){
		ans = a;
	}

	cout<<ans<<endl;

	return 0;
}
