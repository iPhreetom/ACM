
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int n,t;
double c;

int a[312345];
int m;
int p[312345];
long long pre[312345];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>t>>c;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i != 0){
			pre[i] = pre[i-1]+a[i];
		}
		else pre[0] = a[0];
	}
	// for(int i=0;i<n;i++){
	// 	cout<<pre[i]<<' ';
	// }cout<<endl;

	cin>>m;
	for(int i=0;i<m;i++){
		cin>>p[i];
	}

	double mean = 0;
	// for(int i=0;i<n;i++){
	// 	mean = (mean + (double)a[i]/(double)t)/c;
	// }

	double real = 0;
	int j = 0;
	for(int i=0;i<m;i++){
		int cyc = min(t,p[i]);
		// cout<<cyc<<endl;
		if(n > 1){
			real = (pre[p[i]-1] - pre[p[i]-cyc-1])/(double)cyc;
		}
		else{
			real = a[0];
		}

		for(;j<p[i];j++){
			mean = (mean + (double)a[j]/(double)t)/c;
		}
		double er = (double)(abs(mean-real))/real;
		// cout<<real<<' '<<mean<<' '<<er<<endl;
		printf("%.5lf %.5lf %.5lf\n",real,mean,er);
	}
	return 0;
}
