#include<bits/stdc++.h>
using namespace std;


int n,m;
string s[101];
int a[101][101];
int ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	memset(a,0,sizeof(a));

	for(int i=n-1;i>=0;i--){
		for(int j = m-1;j>=0;j--){
			/*
			找到一个不符合的情况，把其作为右下角
			把原来的值通过直接*temp 变成符合情况的xx
			*/
			int q;
			if(s[i][j] == 'B'){
				q = -1;
				if(a[i][j] != q){
					ans++;
					int temp = q - a[i][j];
					for(int k=0;k<=i;k++){
						for(int l=0;l<=j;l++){
							a[k][l] += temp;
						}
					}
				}
				else{
					continue;
				}
			}
			else{//W
				q = 1;
				if(a[i][j] != q){
					ans++;
					int temp = q - a[i][j];
					for(int k=0;k<=i;k++){
						for(int l=0;l<=j;l++){
							a[k][l] += temp;
							// printf("%d(%d %d) ",a[k][l],k,l);
						}
						// cout<<endl;
					}
				}
				else{
					continue;
				}
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}
