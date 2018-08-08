#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int a[3];
int b[3];
int c[3];
int d[3];
int e[3];
int f[3];
int g[3];
int h[3];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	for(int i=0;i<3;i++){
		cin>>b[i];
	}
	for(int i=0;i<3;i++){
		cin>>c[i];
	}
	for(int i=0;i<3;i++){
		cin>>d[i];
	}
	for(int i=0;i<3;i++){
		cin>>e[i];
	}
	for(int i=0;i<3;i++){
		cin>>f[i];
	}
	for(int i=0;i<3;i++){
		cin>>g[i];
	}
	for(int i=0;i<3;i++){
		cin>>h[i];
	}

	vector<double> arr;
	while(next_permutation(a,a+3)){
		while(next_permutation(b,b+3)){
			while(next_permutation(c,c+3)){
				while(next_permutation(d,d+3)){
					while(next_permutation(e,e+3)){
						while(next_permutation(f,f+3)){
							while(next_permutation(g,g+3)){
								while(next_permutation(h,h+3)){
									arr.clear();

								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
