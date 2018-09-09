#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,f,u,d;
	cin>>n>>f>>u>>d;
	int a[4];
	int b[4];
	for (int i=0; i<2; i++){
	    for (int j=0; j<3; j++){
	        cin>>a[i];
	    }
		for (int j=0; j<3; j++){
			cin>>b[i];
		}
	}

	for (int i=0; i<3; i++){
		int tp = f;
	    if(i == 0){
			tp += a[i];
		}
		if(i == 1){
			tp -= a[i];
		}
		if(i == 2){
			tp = -tp;
		}
		int num = 0;
		int q = tp;
		for (int j=0; j<3; j++){
			tp = q;
			if(j == 0){
				tp += b[j];
				if(tp >= u){
					num += 3;
				}
				else if(tp <= d){

				}
				else{
					num += 2;
				}
			}
			if(j == 1){
				tp -= b[j];
				if(tp >= u){
					num += 3;
				}
				else if(tp <= d){

				}
				else{
					num += 2;
				}
			}
			if(j == 2){
				tp = -tp;
				if(tp >= u){
					num += 3;
				}
				else if(tp <= d){

				}
				else{
					num += 2;
				}
			}
		}
		if(num == 9){
			
		}
	}
	return 0;
}
