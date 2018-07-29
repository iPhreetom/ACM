
#include<bits/stdc++.h>
using namespace std;

int n,k;



int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int res = k;
	int count = 2;
	int last = 1;
	int ad = (n-k-1)%res;
	int len = (n-k-1)/res*2+2;
	if(ad == 0){
		cout<<len<<endl;
	}
	else{
		if(ad == 1)cout<<len+1<<endl;
		else if(ad == 2)cout<<len+2<<endl;
		else cout<<len+2<<endl;
	}
	len = (n-k-1)/res+1;

	for(int i=1;i<=res;i++){
		if(ad!=0)len++;
		for(int j=1;j<=len;j++){
			cout<<last<<' '<<count++<<endl;
			last = count-1;
		}
		last = 1;
		if(ad!=0){
			len--;
			ad--;
		}
	}
	return 0;
}
