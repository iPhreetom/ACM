//暴力枚举 -- 基础
#include<bits/stdc++.h>
using namespace std;

long long ans=0;
long long n=0,q,k;
vector<long long> lis;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(long long i=1;i<=9;i++){
		lis.push_back(i+i*10);
	}
	for(long long i=1;i<=9;i++){
		for(long long j=0;j<=9;j++){
			lis.push_back(i+i*1000+j*10+j*100);
		}
	}
	for(long long i=1;i<=9;i++){
		for(long long j=0;j<=9;j++){
			for(long long k=0;k<=9;k++){
				lis.push_back(i+i*100000+j*10+j*10000+k*100+k*1000);
			}
		}
	}
	for(long long i=1;i<=9;i++){
		for(long long j=0;j<=9;j++){
			for(long long k=0;k<=9;k++){
				for(long long z=0;z<=9;z++){
					lis.push_back(i+i*10000000+j*10+j*1000000+k*100+k*100000+z*1000+z*10000);
				}
			}
		}
	}
	for(long long i=1;i<=9;i++){
		for(long long j=0;j<=9;j++){
			for(long long k=0;k<=9;k++){
				for(long long z=0;z<=9;z++){
					for(long long x=0;x<=9;x++){
						lis.push_back(i+j*10+k*100+z*1000+x*10000+x*100000+z*1000000+k*10000000+j*100000000+i*1000000000);
					}
				}
			}
		}
	}
	lis.push_back(100000000001);
	cin>>k>>q;
	for(long long i=0;i<k;i++){
		ans+=lis[i];
		ans%=q;
	}
	cout<<ans<<endl;
	return 0;
}
