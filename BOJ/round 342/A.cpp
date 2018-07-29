#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,a,b,c,ans=0;
	cin>>n>>a>>b>>c;

	long long d = b-c;

	if(n < b){
		cout<<n/a<<endl;
	}
	else{
		if(a > d){
			ans += (n-b+1)/d;//bug：当剩余的钱（使用减法后），不能再够一个d时。我们还是能够再买一个b的
			ans += (n-d*ans)/a; //如果没看qdd的代码，模拟的这个bug是找不出来的，存在解决方案么
		}
		else{
			ans += n/a;
		}
		cout<<ans<<endl;
	}

    return 0;
}
