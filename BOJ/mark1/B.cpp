#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;

	int irbig = 0;
	int ilbig = 0;
	int nrbig = -1;
	int nlbig = -1;
	int l,r;
	int ln=0,rn=0;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		ln+=l;
		rn+=r;

		if(nrbig < l-r){
			irbig = i+1;
			nrbig = l-r;
		}
		else if(nlbig < r-l){
			ilbig = i+1;
			nlbig = r-l;
		}
	}
	if(irbig == 0 || ilbig == 0){
		cout<<0<<endl;
	}
	else{
		if(abs(ln-rn+2*nlbig) > abs(rn-ln+2*nrbig)){
			cout<<ilbig<<endl;
		}
		else{
			cout<<irbig<<endl;
		}
	}
	// printf("r max:%d l max: %d",nrbig,nlbig);
	return 0;
}
