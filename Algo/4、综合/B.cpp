#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


// int a[2123];
vector<int> a(21234);


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	while(cin>>n){

		for(int i=0;i<=n;i++){
			cin>>a[i];
		}

		for(int i=0;i<=n;i++){
			// cout<<"----:"<<i<<"-----"<<endl;
			if(a[i] != 0){
				if(i == n){
					if(i!=0 && a[i]>0)cout<<'+';
					cout<<a[i]<<endl<<endl;
				}else if(i == n-1){
					if(a[i] != 1 && a[i] != -1){
						if(i!=0 && a[i]>0)cout<<'+';
						cout<<a[i]<<"x";
					}
					else{
						if(i!=0 && a[i] >0)cout<<'+';
						if(a[i] < 0)cout<<'-';
						cout<<"x";
					}
				}else{
					if(a[i] != 1 && a[i] != -1){
						if(i!=0 && a[i]>0)cout<<'+';
						cout<<a[i]<<"x^"<<n-i;
					}
					else{
						if(i!=0 && a[i] >0)cout<<'+';
						if(a[i] < 0)cout<<'-';
						cout<<"x^"<<n-i;
					}
				}
			}
		}

		if(a[n] == 0)cout<<endl<<endl;
	}
	return 0;
}
