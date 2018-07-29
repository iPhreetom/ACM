// 989C 构造矩阵
// 	一句话描述：
// 		通过选取极限情况，简单的构造出解
// 	总结：
// 		构造解总是考虑易于构造的情况
// 		尽量的简化构造方法
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int a,b,c,d;
char mp[100][100];


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;

	int n=50,m=50;

	for(int i=0;i<25;i++){
		for(int j=0;j<25;j++){
			mp[i][j]='A';
		}
	}

	for(int i=25;i<50;i++){
		for(int j=0;j<25;j++){
			mp[i][j]='B';
		}
	}

	for(int i=0;i<25;i++){
		for(int j=25;j<50;j++){
			mp[i][j]='C';
		}
	}


	for(int i=25;i<50;i++){
		for(int j=25;j<50;j++){
			mp[i][j]='D';
		}
	}





	a--;
	for(int i=49;a!=0;i-=2){
		for(int j=0;a!=0 && j<25;j+=2){
			if(a!=0){
				mp[i][j]='A';
				a--;
			}
			else{
				break;
			}
		}
	}

	b--;
	for(int i=0;b!=0;i+=2){
		for(int j=0;b!=0 && j<25;j+=2){
			if(b!=0){
				mp[i][j]='B';
				b--;
			}
			else{
				break;
			}
		}
	}

	c--;
	for(int i=49;c!=0;i-=2){
		for(int j=25;c!=0 && j<50;j+=2){
			if(c!=0){
				mp[i][j]='C';
				c--;
			}
			else{
				break;
			}
		}
	}

	d--;
	for(int i=0;d!=0;i+=2){
		for(int j=25;d!=0 && j<50;j+=2){
			if(d!=0){
				mp[i][j]='D';
				d--;
			}
			else{
				break;
			}
		}
	}
	cout<<50<<' '<<50<<endl;
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			cout<<mp[i][j];
		}
		cout<<endl;
	}

	return 0;
}
