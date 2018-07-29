#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin>>a;

	int lt = -1;
	int mx = 1;
	for(int i=0;i<=a.size();i++){
		if(i == a.size()){
			mx = max(i-lt , mx);
			lt = i;
		}
		if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' || a[i] == 'Y'){
			mx = max(mx,i-lt);
			lt = i;
		}
	}
	cout<<mx<<endl;
	return 0;
}
