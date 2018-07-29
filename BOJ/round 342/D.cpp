#include<iostream>
using namespace std;

int sg[1000000][3],l,r;
int ans[1000000];
string a;


/*
不相等时，先退一位能不能相等
	如果为0怎么办：向前接位？直接返回0
还不相等，直接去两个数


左边：
	如果能够
*/

int solve(){
	if(a.size() & 1){//odd
		for(int i=0;i<a.size()/2;i++){
			sg[i][0] = 1;//可以退位
		}
		sg[a.size()][0] = 1;
		sg[a.size()][1] = 1;
		for(int i=a.size()/2+1;i<a.size();i++){
			sg[i][1] = 1;//可以向前进位
		}

		for(int i=0,j=a.size()-1;i<a.size()/2;i++,j--){
			if(a[i] != a[j]){
				if(sg[i-1][0] == 1 && sg[j+1][1] == 1){
					l = (a[i]-'0')*10 + (a[i-1]-'0');
					int k = j+1;
					while(sg[k][1] == 1 && a[k]-'0' == 0){
						a[k] = '9';
						if(sg[++k][1] == 1)continue;
						else return 0;
					}
					r = (a[j]-'0')+10;

					if(l == r){
						ans[i] = 9;
						ans[j] = l-9;
					}
					else{
						if(sg[i-2][0] == 1){
							l -= 1;
							//在字符的基础上直接加10，并且标记
							//标记：？当比对不行的时候，不能再向后退位了么？
						}
					}
				}
			}
			else{
				if(a[i] == '1'){

				}
			}
		}
	}
	else{//
		for(int i=0;i<a.size()/2;i++){
			sg[i][0] = 1;//可以退位
		}
		for(int i=a.size()/2;i<a.size();i++){
			sg[i][1] = 1;//可以向前进位
		}

	}
}

int main(){
	cin>>a;

	if(a.size() == 1){
		if(a.size() & 1){//odd
			cout<<0<<endl;
		}
		else{
			cout<<(a[0]-'0')/2<<endl;
		}
	}
	else{
		if(solve() == 0){
			cout<<solve<<endl;
		}
	}

	return 0;
}
