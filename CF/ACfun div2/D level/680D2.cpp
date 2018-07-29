#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

int n,ans,sum;

void findit(int m,int num,int add){
	if(m <= 7){
		num += m;
		add += m;

		if(ans == num){
			sum = max(sum,add);
		}
		else if(ans < num){
			sum = add;
			ans = num;
		}
		return ;
	}

	int a = pow(m,1.0/3.0);
	int a1 = a-1;

	findit(m-a*a*a,num+1,add+a*a*a);
	findit(a*a*a-a1*a1*a1-1,num+1,add+a1*a1*a1);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	cin>>n;

	findit(n,0,0);
	cout<<ans<<' '<<sum<<endl;

	return 0;
}
