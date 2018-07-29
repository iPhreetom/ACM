// 数论 -- 数学特性 -- 公共

//printf()
//cout 不能加endl ,可以用cout.tie(0);
#include<bits/stdc++.h>
using namespace std;

long long n;
long long a,b;
long long mul;
long long di;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(register int i=0;i<n;i++){
		cin>>a>>b;
		mul = a*b;
		double w = pow(mul,1.0/3.0);
		di = 0.5+w;
		if(di*di*di == mul){
			if(a%di==0 && b%di==0){
				// printf("Yes\n");
				// cout<<"Yes"<<endl;
				cout<<"Yes\n";
			}
			else{
				// printf("No\n");
				// cout<<"No"<<endl;
				cout<<"No\n";
			}
		}
		else{
			// printf("No\n");
			// cout<<"No"<<endl;
			cout<<"No\n";

			// cout<<w<<' '<<di<<endl;
		}
	}
	return 0;
}
